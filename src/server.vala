using Gee;

namespace yrcd {
  class yrcd_server : Object {
    private SocketService ss = new SocketService();
    private MainLoop loop = new MainLoop();
    private yrcd_router router = new yrcd_router();
    private HashMap<int, yrcd_user> userlist = new HashMap<int, yrcd_user>();
    private int user_counter = 0;
    public int new_userid() {
      user_counter++;
      return user_counter;
    }
    public void log (string msg) {
      stdout.printf("LOG: %s\n", msg);
    } 
    public yrcd_server () {
      log("Initializing server: %s %s".printf(yrcd_constants.software, yrcd_constants.version));
      foreach (var k in yrcd_constants.listen_ports) {
        add_port(k);
      }
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
      userlist[user.id] = user;
      process_request.begin(user);
      return true;
    }
    private async void process_request(yrcd_user user) {
      log("data streams open, entering main loop.");
      while (true) {
        if (!user.sock.is_connected()) {
          log("Socket not connected...breaking");
          break;
        }
        try {
          string msg = yield user.dis.read_line_async (Priority.DEFAULT);
          router.route(user, msg);
        } catch (Error e) {
          log("Error encountered in socket loop: %s".printf(e.message));
        }
      }
    }
  }
}
