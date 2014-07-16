namespace yrcd {
  class yrcd_server : Object {
    private SocketService ss = new SocketService();
    private MainLoop loop = new MainLoop();
    public void log (string msg) {
      stdout.printf("LOG: %s\n", msg);
    } 
    public void init () {
      ss.incoming.connect(on_connection);
      ss.start();
      loop.run();
    }
    public void add_port (uint16 port) {
      log("attempting to add port %d".printf(port));
      try {
        ss.add_inet_port(port, null);
        log("port %d successfully added".printf(port));
      } catch (Error e) {
        log("Add Port error: %s".printf(e.message));
      }
    }
    private bool on_connection (SocketConnection conn) {
      log("Connection received, routing to process_request.");
      yrcd_user user  = new yrcd_user(conn, this);
      process_request.begin(user);
      return true;
    }
    private async void process_request(yrcd_user user) {
      log("data streams open, entering main loop.");
      while (true) {
        try {
          string msg = yield user.dis.read_line_async (Priority.DEFAULT);
          log("Received line %s".printf(msg));
          //example output dos.put_string("%s\n");
          //todo - create router class.
        } catch (Error e) {
          log("Error encountered in socket loop: %s".printf(e.message));
        }
      }
    }
  }
}
