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
    public bool nick_set { get; set; }
    public bool user_set { get; set; }
    public bool reg_complete { get; set; }
    public string ip;
    public yrcd_user (SocketConnection conn, yrcd_server _server) {
      sock = conn;
      server = _server;
      ip = get_ip();
      dis = new DataInputStream(sock.input_stream);
      dos = new DataOutputStream(sock.output_stream);
      id = server.new_userid();
      epoch = new DateTime.now_utc().to_unix();
      server.log("User connected from %s with ID %d".printf(ip,id));
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
    public void change_nick (string[] args) {
      if (args.length < 2) {
        server.log("User %d attempted NICK with invalid arguments".printf(id));
      }
      string oldnick = nick;
      nick = args[1];
      if (!nick_set) {
        server.log("User %d set nick to %s".printf(id,nick));
        nick_set = true;
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
        realname = args[4];
        if (nick_set) {
          reg_finished();
        }
      } else {
        server.log("User %d attempted user registration while already registered".printf(id));
      }
    }
    public void reg_finished () {
      reg_complete = true;
      server.log("User %d finished registration with mask %s and realname %s".printf(id,get_hostmask(),realname));
    }
    public void update_timestamp() {
      time_last_rcv = new DateTime.now_utc().to_unix();
    }
    public string get_hostmask() {
      var builder = new StringBuilder();
      builder.append(nick);
      builder.append("!");
      builder.append(ident);
      builder.append("@");
      builder.append(ip);
      return builder.str;
    }
  }
}
