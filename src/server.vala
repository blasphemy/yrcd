using Gee;

namespace yrcd {
  class yrcd_server : Object {
    private SocketService ss = new SocketService();
    private MainLoop loop = new MainLoop();
    private yrcd_router router = new yrcd_router();
    private HashMap<int, yrcd_user> userlist = new HashMap<int, yrcd_user>();
    private int user_counter = 0;
    public int64 epoch;
    public int max_users = 0;
    public yrcd_numeric_wrapper numeric_wrapper = new yrcd_numeric_wrapper();
    public int new_userid() {
      user_counter++;
      return user_counter;
    }
    public void log (string msg) {
      stdout.printf("LOG: %s\n", msg);
    } 
    public yrcd_server () {
      log("Initializing server: %s %s".printf(yrcd_constants.software, yrcd_constants.version));
      epoch = new DateTime.now_utc().to_unix();
      add_listeners();
      ss.incoming.connect(on_connection);
      ss.start();
      loop.run();
    }
    public void remove_user (int id) {
      userlist.unset(id);
    }
    public void add_listeners () {
      foreach (var k in yrcd_constants.listen_ips) {
        foreach (var j in yrcd_constants.listen_ports) {
          log("Adding listener on IP: %s port %d".printf(k,j));
          SocketAddress serversock = null;
          InetAddress inetaddr = new InetAddress.from_string(k);
          SocketAddress sockaddr = new InetSocketAddress(inetaddr,j);
          try {
            ss.add_address(sockaddr, GLib.SocketType.STREAM, GLib.SocketProtocol.DEFAULT, ss, out serversock);
          } catch (Error e) {
            log("Error opening socket: %s".printf(e.message));
          }
        }
      }
    }
    private bool on_connection (SocketConnection conn) {
      log("Connection received, routing to process_request.");
      yrcd_user user  = new yrcd_user(conn, this);
      userlist[user.id] = user;
      int users = userlist.size;
      if (users > max_users) {
        max_users = users;
        log("New max amount of users: %d".printf(max_users));
      }
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
    public string ut_to_utc(int64 ut) {
    var time = new DateTime.from_unix_utc(ut);
    return time.to_string();
    }
    public bool check_nick_collision (string nicktocheck) {
      foreach (yrcd_user user in userlist) {
        if (user.nick_set) {
          if (user.nick == nicktocheck) {
            return true;
          }
        }
      }
      return false;
    }
    public string? get_user_by_nick (string nicktocheck) {
      foreach (yrcd_user k in userlist) {
        if (k.nick_set) {
          if (k.nick == nicktocheck) {
            return k.nick;
          }
        }
      }
      return null;
    }
  }
}
