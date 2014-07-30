using Gee;

namespace yrcd {
  class yrcd_server : Object {
    private SocketService ss = new SocketService();
    private yrcd_router router;
    public HashMap<int, yrcd_user> userlist = new HashMap<int, yrcd_user>();
    public HashMap<string, yrcd_channel> channellist;
    private int user_counter = 0;
    public int64 epoch;
    public int max_users = 0;
    public yrcd_numeric_wrapper numeric_wrapper = new yrcd_numeric_wrapper();
    public Config config;
    public int new_userid() {
      user_counter++;
      return user_counter;
    }
    public void log (string msg) {
      stdout.printf("LOG: %s\n", msg);
    } 
    public yrcd_server (Config _config) {
      config = _config;
      log("Initializing server: %s %s".printf(yrcd_constants.software, yrcd_constants.version));
      epoch = new DateTime.now_utc().to_unix();
      add_listeners();
      router = new yrcd_router(this);
      channellist = new HashMap<string, yrcd_channel>();
      ss.incoming.connect(accept_connection);
      ss.start();
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
      router.process_user(conn);
      return true;
    }
    public string ut_to_utc(int64 ut) { //why does this function even exist? TODO: Remove me.
      DateTime time = new DateTime.from_unix_utc(ut);
      return time.to_string();
    }
    public yrcd_user? get_user_by_nick (string nicktocheck) {
      foreach (yrcd_user k in userlist) {
        if (k.nick.down() == nicktocheck.down()) { //we are case-insensitive in this context.
          return k;
        }
      }
      //Nothing found, so return null. This is useful in other functions to find if a user exists by that name at all.
      return null;
    }
    public yrcd_channel get_channel_by_name(string nametocheck) {
      log(@"Looking for channel $nametocheck");
      if (channellist[nametocheck] != null) {
        log(@"channel $nametocheck  found");
        return channellist[nametocheck];
      }
      //Nothing found, so return null. This is useful in other functions to find if a channel exists by that name at all.
      log(@"Channel $nametocheck not found, creating it");
      yrcd_channel chan = new yrcd_channel(this, nametocheck);
      channellist[chan.name.down()] = chan;
      return chan;
    }
    public string secure_hash (string in) {
      StringBuilder builder = new StringBuilder();
      //hash the input data with salt
      builder.append(GLib.Checksum.compute_for_string(ChecksumType.MD5,in));
      //make it longer if needed
      while (builder.str.length < in.length) {
        builder.append(GLib.Checksum.compute_for_string(ChecksumType.MD5,builder.str));
      }
      //and shorten it to the original length.
      builder.truncate(in.length);
      return builder.str;
    }
  }
}
