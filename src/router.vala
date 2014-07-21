using Gee;

namespace yrcd {
  class yrcd_router : Object {
    public void route (yrcd_user user, string? msg) {
      if (msg == null) {
        user.server.log("Received null message, disconnecting user %d".printf(user.id));
        user.quit(null);
        return;
      }
      string stripped = strip_end(msg);
      string[] args = tokenize(stripped);
      if (args[0] != null) {
        user.server.log("USER %d: received line %s".printf(user.id,stripped));
        user.update_timestamp();
        switch (args[0].down()) {
          case "quit" :
            user.server.log("Received QUIT");
            user.quit(null);
            break;
          case "nick" :
            user.change_nick(args);
            break;
          case "user" :
            user.user_reg(args);
            break;
          case "privmsg" :
            privmsg_handler(args);
            break;
        }
      }
    }
    public void privmsg_handler(string[] args) {
     /*
      * No plans to support sending to hostmasks for now.
      */
      if (args.length < 2) {
        //todo ERR_NORECIPIENT
      } else if (args.length < 3) {
        //todo ERR_NOTEXTTOSEND
      } else {
        foreach(string k in yrcd_constants.chan_prefixes) {
          if (k in args[1]) {
            //presumably targeting a channel...
            return;
          }
        }
      }
      return;
    }
    public string strip_end (string msg) {
      var builder = new StringBuilder ();
      builder.append(msg);
      builder.truncate(builder.len - 1);
      return builder.str;
    }
    public string[] tokenize (string msg) {
      return msg.split(" ");
    }
  }
}
