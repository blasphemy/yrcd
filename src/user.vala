using Gee;

namespace yrcd {
  class yrcd_user : Object {
    public SocketConnection sock { get; set; }
    public DataInputStream dis { get; set; }
    public DataOutputStream dos { get; set; }
    public yrcd_server server { get; set; }
    public int id { get; set; }
    private int64 time_last_rcv;
    public int64 epoch;
    public string nick { get; set; }
    public string ident { get; set; }
    public string realname { get; set; }
    public bool user_set { get; set; }
    public bool reg_complete { get; set; }
    public string ip;
    public string host;
    public HashMap<int,yrcd_channel> user_chanels = new HashMap<int,yrcd_channel>();
    public yrcd_user (SocketConnection conn, yrcd_server _server) {
      sock = conn;
      server = _server;
      ip = get_ip();
      dis = new DataInputStream(sock.input_stream);
      dos = new DataOutputStream(sock.output_stream);
      id = server.new_userid();
      epoch = new DateTime.now_utc().to_unix();
      host = get_host();
      server.log("User connected from %s with ID %d".printf(host,id));
    }
    public bool isnickset() {
      if (nick == null) {
        return false;
      } else {
        if (nick.length > 0) {
          return true;
        } else {
          return false;
        }
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
    public void quit (string? msg) {
      try {
        sock.get_socket().close();
        server.remove_user(id);
      } catch (Error e) {
        server.log("Error closing socket: %s".printf(e.message));
      }
    }
    public void join (yrcd_channel chan) {
      if (chan.add_user(this)) {
        user_chanels[chan.cid] = chan;
      }
    }
    public void change_nick (string[] args) {
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
      if (!isnickset()) {
        server.log("User %d set nick to %s".printf(id,nick));
        if (!reg_complete && user_set) {
          reg_finished();
        }
      } else {
        server.log("User %d changed nick from %s to %s".printf(id,oldnick,nick));
      }
    }
    public void user_reg (string[] args) {
      if (!user_set) {
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
        if (isnickset()) {
          reg_finished();
        }
      } else {
        server.log("User %d attempted user registration while already registered".printf(id));
      }
    }
    public void reg_finished () {
      reg_complete = true;
      server.log("User %d finished registration with mask %s and realname %s".printf(id,get_hostmask(),realname));
      fire_numeric(RPL_WELCOME, nick, ident, host);
      fire_numeric(RPL_YOURHOST, yrcd_constants.sname, yrcd_constants.software, yrcd_constants.version);
      fire_numeric(RPL_CREATED, "%s".printf(server.ut_to_utc(server.epoch)));
      fire_numeric(RPL_MYINFO, yrcd_constants.sname, yrcd_constants.version, "", ""); //No modes yet....
    }
    public void update_timestamp() {
      time_last_rcv = new DateTime.now_utc().to_unix();
    }
    public string get_hostmask() {
      string hm = nick + "!" + ident + "@" + host;
      return hm;
    }
    public string get_host() {
      try {
        InetAddress address = new InetAddress.from_string(ip);
        Resolver resolver = Resolver.get_default();
        string hostname = resolver.lookup_by_address(address,null);
        GLib.List<InetAddress> addresses = resolver.lookup_by_name(hostname);
        bool match = false;
        foreach (InetAddress k in addresses) {
          if (k.to_string() == ip) {
            match = true;
          }
        }
        if (!match) {
          hostname = ip;
        }
        return hostname;
      } catch (Error e) {
        server.log("Error resolving user %d IP %s".printf(id,ip));
        return ip;
      }
    }
    public void send_line(string msg) {
      try {
        dos.put_string("%s\n".printf(msg));
      } catch (Error e) {
        server.log("Error sending message to UID %d : %s".printf(id,e.message));
      }
    }
    public void fire_numeric(int numeric, ...) {
      va_list args = va_list();
      string msg = ":%s %.3d %s :".printf(yrcd_constants.sname,numeric,nick);
      string msg2 = server.numeric_wrapper.numerics[numeric].vprintf(args);
      msg += msg2;
      send_line(msg);
    }
  }
}
