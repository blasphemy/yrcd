using Gee;

namespace yrcd {
  class yrcd_user : Object {
    public SocketConnection sock { get; set; }
    public DataInputStream dis { get; set; }
    public DataOutputStream dos { get; set; }
    public yrcd_server server { get; set; }
    public int id { get; set; }
    private DateTime time_last_rcv;
    private DateTime epoch;
    private int64 check_ping_at;
    private bool awaiting_response;
    private uint ping_timer;
    public string nick { get; set; }
    public string ident { get; set; }
    public string realname { get; set; }
    public bool user_set { get; set; }
    public bool nick_set { get; set; }
    public bool registered { get; set; }
    public string ip; 
    public string host;
    public HashMap<string,yrcd_channel> user_chanels;
    public yrcd_user (SocketConnection conn, yrcd_server _server) {
      user_chanels = new HashMap<string,yrcd_channel>();
      sock = conn;
      server = _server;
      ip = get_ip();
      dis = new DataInputStream(sock.input_stream);
      dos = new DataOutputStream(sock.output_stream);
      id = server.new_userid();
      epoch = new DateTime.now_utc();
      time_last_rcv = new DateTime.now_utc();
      host = ip;
      hostname_lookup.begin();
      awaiting_response = false;
      check_ping_at = epoch.to_unix() + server.config.ping_invertal;
      ping_timer = setup_ping_timer();
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
            send_line("PING :" + server.config.sname);
            awaiting_response = true;
          }
        }
        check_ping_at = now + server.config.ping_invertal;
      }
    }
    public string get_ip () {
      try { 
        InetSocketAddress inetsockaddr = sock.get_remote_address() as InetSocketAddress;
        string ip = inetsockaddr.get_address().to_string();
        return ip;
      } catch (Error e) {
        server.log("Error getting user ip: %s".printf(e.message));
        return "unknown";
      }
    }
    public void quit (string? msg) { //TODO Finish this.
      try {
        if (msg == null) {
          msg = "Quit";
        }
        foreach (yrcd_channel k in user_chanels.values) {
          k.quit(this, msg);
        }
        Source.remove(ping_timer);
        send_line("ERROR :Closing Link: %s (%s)".printf(host,msg));
        sock.get_socket().close();
        server.remove_user(id);
      } catch (Error e) {
        server.log("Error closing socket: %s".printf(e.message));
      }
    }
    public void part (yrcd_channel chan, string? msg) {
      if (user_chanels[chan.name] == null) {
        return;
      }
      if (msg == null) {
        msg = "Leaving";
      }
      user_chanels.unset(chan.name);
      chan.part(this,msg);
    }
    public void join (yrcd_channel chan) {
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
      if (server.get_user_by_nick(args[1]) != null) {
        fire_numeric(ERR_NICKNAMEINUSE, args[1]);
        return;
      }
      foreach (string k in yrcd_constants.forbidden_nick_chars) {
        if (k in args[1]) {
          fire_numeric(ERR_ERRONEOUSNICKNAME, args[1]);
          return;
        }
      }
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
      fire_numeric(RPL_YOURHOST, server.config.sname, yrcd_constants.software, yrcd_constants.version);
      fire_numeric(RPL_CREATED, "%s".printf(server.ut_to_utc(server.epoch)));
      fire_numeric(RPL_MYINFO, server.config.sname, yrcd_constants.version, "", ""); //No modes yet....
      fire_motd();
    }
    public void update_timestamp() {
      time_last_rcv = new DateTime.now_utc();
      awaiting_response = false;
    }
    public string get_hostmask() { //TODO Implement cloaking here.
      string hm = nick + "!" + ident + "@" + cloaked_host();
      return hm;
    }
    public void send_line(string msg) {
      try {
        dos.put_string("%s\n".printf(msg));
        server.log("sending to %s: %s".printf(nick,msg));
      } catch (Error e) {
        server.log("Error sending message to UID %d : %s".printf(id,e.message));
        quit("Error: %s".printf(e.message));
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
      send_line(msg);
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
    public string cloaked_host() {
      StringBuilder builder = new StringBuilder();
      int i;
      string[] j = host.split(".");
      builder.append(server.secure_hash(j[0]));
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
