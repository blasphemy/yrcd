namespace yrcd {
  class yrcd_user : Object {
    public SocketConnection sock { get; set; }
    public DataInputStream dis { get; set; }
    public DataOutputStream dos { get; set; }
    public yrcd_server server { get; set; }
    public int id { get; set; }
    public string nick { get; set; }
    public string ident { get; set; }
    public string realname { get; set; }
    public bool nick_set { get; set; }
    public bool user_set { get; set; }
    public bool reg_complete { get; set; }
    public yrcd_user (SocketConnection conn, yrcd_server _server) {
      sock = conn;
      server = _server;
      server.log("User constructor called, opening data streams");
      dis = new DataInputStream(sock.input_stream);
      dos = new DataOutputStream(sock.output_stream);
      id = server.new_userid();
      server.log("User registered with ID %d".printf(id));
    }
    public void quit (string? msg) {
      try {
        sock.get_socket().close();
      } catch (Error e) {
        server.log("Error closing socket: %s".printf(e.message));
      }
    }
    public void change_nick (string newnick) {
      nick = newnick;
      if (!nick_set) {
        nick_set = true;
        if (!reg_complete && user_set) {
          reg_complete = true;
        }
      }
    }
    public void user_reg (string[] args) {
      if (!user_set) {
        ident = args[1];
        realname = args[2];
        if (nick_set) {
          server.log("User %d registration complete.".printf(id));
        }
      } else {

      }
    }
  }
}
