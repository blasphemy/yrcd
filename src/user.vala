using Gee;

namespace yrcd {
  class User : BaseObject {
    public SocketConnection sock { get; set; }
    public DataInputStream dis { get; set; }
    public OutputStream outs { get; set; }
    public Server server { get; set; }
    public int id { get; set; }
    private DateTime time_last_rcv;
    private DateTime epoch;
    private int64 check_ping_at;
    private bool awaiting_response;
    public string nick { get; set; }
    public string ident { get; set; }
    public string realname { get; set; }
    public bool user_set { get; set; }
    public bool nick_set { get; set; }
    public bool registered { get; set; }
    public string ip; 
    private string host;
    public HashMap<string,Channel> user_chanels;
    public GLib.List<uint> asources;
    public User (SocketConnection conn, Server _server) {
      user_chanels = new HashMap<string,Channel>();
      sock = conn;
      server = _server;
      ip = get_ip();
      dis = new DataInputStream(sock.input_stream);
      outs = sock.output_stream;
      asources.append(Idle.add(() => { return sflush(); }, Priority.DEFAULT));
      id = server.new_userid();
      epoch = new DateTime.now_utc();
      time_last_rcv = new DateTime.now_utc();
      host = ip;
      hostname_lookup.begin();
      awaiting_response = false;
      check_ping_at = epoch.to_unix() + server.config.ping_invertal;
      asources = new GLib.List<uint>();
      asources.append(setup_ping_timer());
      registered = false;
      server.log("User connected from %s with ID %d".printf(host,id));
    }
    private uint setup_ping_timer() {
      uint t = Timeout.add_seconds_full(Priority.DEFAULT, 10, () => {
          if (!sock.get_socket().is_connected()) { return false; }
          check_ping();
          return true;
          });
      return t;
    }
    private void check_ping() {
      server.log("check ping called on user %d".printf(id));
      int64 now = new DateTime.now_utc().to_unix();
      int64 last = time_last_rcv.to_unix();
      if (now > check_ping_at) {
        if (check_ping_at > last) {
          if (awaiting_response) {
            quit("Ping timeout: %d seconds".printf(server.config.ping_invertal));
          } else {
            send_line("PING :" + server.config.sname, Priority.DEFAULT);
            awaiting_response = true;
          }
        }
        check_ping_at = now + server.config.ping_invertal;
      }
    }
    public string get_ip () {
      try {
        InetSocketAddress inet = (InetSocketAddress) sock.get_remote_address();
        if (inet != null) {
          string k = inet.get_address().to_string();
          return k;
        } else {
          return "1.2.3.4";
        }
      } catch (Error e) {
        return "1.2.3.4";
      }
    }
    public void quit (string? msg) { //TODO Finish this.
      try {
        if (msg == null) {
          msg = "Quit";
        }
        GLib.List<User> rec = new GLib.List<User>();
        foreach (Channel k in user_chanels.values) {
          rec.concat(k.get_users());
          k.remove_user(this);
        }
        server.send_to_many(rec, ":%s QUIT :%s".printf(get_hostmask(), msg), Priority.DEFAULT);
        send_line("Error :Closing Link: %s (%s)".printf(host,msg));
        foreach (uint k in asources) {
          Source.remove(k);
          asources.remove(k);
        }
        sock.get_socket().close();
        server.remove_user(id);
      } catch (Error e) {
        server.log("Error closing socket: %s".printf(e.message));
      }
      this.unref();
    }
    public void part (Channel chan, string? msg) {
      if (user_chanels[chan.name] == null) {
        return;
      }
      if (msg == null) {
        msg = "Leaving";
      }
      user_chanels.unset(chan.name);
      chan.part(this,msg);
    }
    public void join (Channel chan) {
      if (chan.add_user(this)) {
        string name = chan.name;
        server.log(@"user $nick joining chan $name");
        user_chanels[chan.name] = chan;
      }
    }
    public void change_nick (string[] args) { //Possible TODO, implement nick validity checker in server.vala, or possibly utils.vala.
      if (args.length < 2) {
        server.log("User %d attempted NICK with invalid arguments".printf(id));
        fire_numeric(ERR_NONICKNAMEGIVEN);
        return;
      }
      if (args[1].length > server.config.max_nick_length && server.config.max_nick_length > 0) { // if they're dumb enough to set it to 0, make it unlimited.
        fire_numeric(ERR_ERRONEOUSNICKNAME);
        return;
      }
      if (server.get_user_by_nick(args[1]) != null) {
        fire_numeric(ERR_NICKNAMEINUSE, args[1]);
        return;
      }
      foreach (string k in Constants.forbidden_nick_chars) {
        if (k in args[1]) {
          fire_numeric(ERR_ERRONEOUSNICKNAME, args[1]);
          return;
        }
      }
      string oldhm = get_hostmask();
      string oldnick = nick;
      nick = args[1];
      if (!nick_set) {
        server.log("User %d set nick to %s".printf(id,nick));
        nick_set = true;
        if (user_set) {
          reg_finished();
        }
      } else {
        server.log("User %d changed nick from %s to %s".printf(id,oldnick,nick));
        var rec = new GLib.List<User>();
        rec.append(this);
        foreach (Channel k in user_chanels.values) {
          rec.concat(k.get_users());
        }
        string to_send = ":%s NICK %s".printf(oldhm,nick);
        server.send_to_many(rec,to_send,Priority.DEFAULT);
      }
    }
    public void user_reg (string[] args) {
      if (!user_set) {
        if (args.length < 5) {
          fire_numeric(ERR_NEEDMOREPARAMS, "USER");
          return;
        }
        ident = args[1];
        if (args[4].has_prefix(":")) {
          args[4] = args[4].replace(":","");
        }
        int i;
        StringBuilder builder = new StringBuilder();
        for (i = 4; i < args.length; i++) {
          builder.append(args[i]);
          builder.append(" ");
        }
        realname = builder.str.strip();
        user_set = true;
        if (nick_set) {
          reg_finished();
        }
      } else {
        server.log("User %d attempted user registration while already registered".printf(id));
        fire_numeric(462);
      }
    }
    public void reg_finished () {
      registered = true;
      server.log("User %d finished registration with mask %s and realname %s".printf(id,get_hostmask(),realname));
      fire_numeric(RPL_WELCOME, nick, ident, host);
      fire_numeric(RPL_YOURHOST, server.config.sname, Constants.software, Constants.version);
      fire_numeric(RPL_CREATED, "%s".printf(server.ut_to_utc(server.epoch)));
      fire_numeric(RPL_MYINFO, server.config.sname, Constants.version, "", ""); //No modes yet....
      fire_motd();
    }
    public void update_timestamp() {
      time_last_rcv = new DateTime.now_utc();
      awaiting_response = false;
    }
    public string get_hostmask() {
      string hm = "%s!%s@%s".printf(nick,ident,get_host());
      return hm;
    }
    /*
    private void send_to_socket (string msg) {
      try {
        if (sock.get_socket().is_connected()) {
          dos.put_string("%s\n".printf(msg));
          server.log("Send to %s: %s".printf(nick,msg));
        } 
      } catch (Error e) {
        server.log("Error sending data to socket %s".printf(e.message));
        quit("Error");
      }

    }
    */
    private bool sflush() {
      try {
        outs.flush();
        return true;
      } catch (Error e) {
        server.log("Error flushing user %s socket".printf(nick));
        return false;
      }
    }
    public void send_line(string msg, int p = Priority.DEFAULT) {
      try {
        size_t bytes_written;
        string buffer = "%s\n".printf(msg);
        outs.write_all(buffer.data, out bytes_written);
        server.log(@"$bytes_written bytes written to $nick buffer");
      } catch (Error e) {
        server.log(@"Error writing to $nick buffer");
        quit("Error");
      }
    }
    public async void hostname_lookup() {
      send_notice("*** Looking up your hostname...");
      Resolver resolv = Resolver.get_default();
      InetAddress add = new InetAddress.from_string(ip);
      string hn;
      GLib.List<InetAddress> addresses;
      bool match = false;
      try {
        hn = yield resolv.lookup_by_address_async(add);
      } catch (Error e) {
        send_notice("*** Unable to resolve your hostname");
        host = ip;
        return;
      }
      try {
        addresses = yield resolv.lookup_by_name_async(hn);
      } catch (Error e) {
        send_notice("*** Unable to resolve your hostname");
        host = ip;
        return;
      }
      foreach (InetAddress k in addresses) {
        if (k.to_string() == ip) {
          match = true;
          break;
        }
      }
      if (!match) {
        host = ip;
        send_notice("*** Your forward and reverse DNS do not match, ignoring hostname");
      } else {
        host = hn;
        send_notice("*** Found your hostname");
        return;
      }
    }
    public void fire_numeric(int numeric, ...) { //TODO Fix this mess. not all numerics will look like this. Formats will also have to be changed in numerics.vala.
      va_list args = va_list();
      string msg = ":%s %.3d %s ".printf(server.config.sname,numeric,nick);
      string msg2 = server.numeric_wrapper.numerics[numeric].vprintf(args);
      msg += msg2;
      send_line(msg, Priority.DEFAULT);
    }
    public void send_notice (string msg) {
      send_line(":%s NOTICE %s :%s".printf(server.config.sname,nick,msg));
    }
    public void fire_motd () {
      fire_numeric(RPL_MOTDSTART, server.config.sname);
      foreach (string line in server.config.motd) {
        fire_numeric(RPL_MOTD, line);
      }
      fire_numeric(RPL_ENDOFMOTD);
    }
    public string get_host() {
      if (server.config.cloaking) {
        return cloaked_host();
      } else {
        return host;
      }
    }
    public string cloaked_host() {
      StringBuilder builder = new StringBuilder();
      int i;
      string[] j = host.split(".");
      builder.append(Utils.secure_hash(j[0], server.config.salt));
      builder.append(".");
      for (i=1;i<j.length;i++) {
        builder.append(j[i]);
        if (i<j.length -1) {
          builder.append(".");
        }
      }
      return builder.str;
    }
  }
}
