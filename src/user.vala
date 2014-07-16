namespace yrcd {
  class yrcd_user : Object {
    public SocketConnection sock { get; set; }
    public DataInputStream dis { get; set; }
    public DataOutputStream dos { get; set; }
    private yrcd_server server { get; set; }
    public yrcd_user (SocketConnection conn, yrcd_server _server) {
      sock = conn;
      server = _server;
      server.log("User constructor called, opening data streams");
      dis = new DataInputStream(sock.input_stream);
      dos = new DataOutputStream(sock.output_stream);
    }
  }
}
