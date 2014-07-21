using Gee;

namespace yrcd {
  class yrcd_router : Object {
    public yrcd_server server;
    public yrcd_router(yrcd_server k) {
      server = k;
    }
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
            privmsg_handler(user,args);
            break;
          case "join" :
            join_handler(user,args);
            break;
        }
      }
    }
    public void join_handler(yrcd_user user, string[] args) {
      if (server.get_channel_by_name(args[1]) == null) {
        yrcd_channel newchan = new yrcd_channel();
        newchan.name = args[1];
        server.channellist[server.new_cid()] = newchan;
        newchan.add_user(user);
      }
    }
    public void privmsg_handler(yrcd_user user, string[] args) {
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
        //if we've reached this point, it's possible it could be a user
        if (server.get_user_by_nick == null) {
          //todo NOT A USER
        }
        //we got this far, not a channel, not a user, call it quits and return
        //fire ERR_NOSUCHNICK?
        return; 
      }
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
