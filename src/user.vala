namespace yrcd {
  class yrcd_user : Object {
    public SocketConnection sock { get; set; }
    public DataInputStream dis { get; set; }
    public DataOutputStream dos { get; set; }
    public yrcd_server server { get; set; }
    public int id { get; set; }
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
  }
}
