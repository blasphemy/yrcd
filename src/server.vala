using Gee;

namespace yrcd {
  class Server : BaseObject {
    private SocketService ss = new SocketService();
    private Router router;
    public HashMap<int, weak User> userlist = new HashMap<int, weak User>();
    public HashMap<string, Channel> channellist;
    private int user_counter = 0;
    public int64 epoch;
    public int max_users = 0;
    public NumericWrapper numeric_wrapper = new NumericWrapper();
    public Config config;
    public int new_userid() {
      user_counter++;
      return user_counter;
    }
    public void log (string msg) {
      stdout.printf("LOG: %s\n", msg);
    } 
    public Server (Config _config) {
      config = _config;
      log("Initializing server: %s %s".printf(Constants.software, Constants.version));
      epoch = new DateTime.now_utc().to_unix();
      add_listeners();
      router = new Router(this);
      channellist = new HashMap<string, Channel>();
      ss.incoming.connect(accept_connection);
      ss.start();
#if REF_TRACKING
      Timeout.add_seconds_full(Priority.DEFAULT, 10, () => { BaseObject.dump_refs(stdout); return true; });
#endif
    }
    public void remove_user (int id) {
      userlist.unset(id);
    }
    public void remove_channel(string name) {
      channellist.unset(name);
    }
    public void add_listeners () {
      foreach (string k in config.listen_ips) {
        foreach (uint16 j in config.listen_ports) {
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
    public bool accept_connection (SocketConnection conn) {
      router.process_user.begin(conn);
      return true;
    }
    public string ut_to_utc(int64 ut) { //why does this function even exist? TODO: Remove me.
      DateTime time = new DateTime.from_unix_utc(ut);
      return time.to_string();
    }
    public User? get_user_by_nick (string nicktocheck) {
      foreach (User k in userlist.values) {
        if (k.nick.down() == nicktocheck.down()) { //we are case-insensitive in this context.
          return k;
        }
      }
      //Nothing found, so return null. This is useful in other functions to find if a user exists by that name at all.
      return null;
    }
    public Channel get_channel_by_name(string nametocheck) {
      log(@"Looking for channel $nametocheck");
      if (channellist[nametocheck.down()] != null) {
        log(@"channel $nametocheck  found");
        return channellist[nametocheck.down()];
      }
      //Nothing found, so return null. This is useful in other functions to find if a channel exists by that name at all.
      log(@"Channel $nametocheck not found, creating it");
      Channel chan = new Channel(this, nametocheck);
      channellist[chan.name.down()] = chan;
      return chan;
    }
    public void send_to_many(GLib.List<User> users,string msg, int p = Priority.DEFAULT) {
      ArrayList<User> final = new ArrayList<User>();
      foreach (User k in users) {
        if (!final.contains(k)) {
          final.add(k);
        }
      }
      foreach (User k in final) {
        k.send_line(msg,p);
      }
    }
  }
}
