using Gee;
/*
   Router.vala. I absolutely hate this file, because if I wasn't so stupid, I would have made commands modular.
 */
namespace yrcd {
  class Router : BaseObject {
    public Server server;
    public Router(Server k) {
      server = k;
    }
    public void route (User user, string? msg) {
      if (msg == null) {
        user.server.log("Received null message, disconnecting user %d".printf(user.id));
        user.quit(null);
        return;
      }
      string stripped = msg.strip();
      string[] args = stripped.split(" ");
      if (args[0] != null) {
        user.server.log("USER %d: received line %s".printf(user.id,stripped));
        user.update_timestamp(); //timestamp should be updated as soon as possible to be accurate. Not that perfect acuracy is a thing in this ircd.
        switch (args[0].down()) {
          case "quit" :
            quit_handler(user,args);
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
          case "pong" : //at this point, ping is just sent as a poke to the user. We don't care what we get back, as long as we get something. About as lazy as it gets.
            break;
          case "motd" :
            user.fire_motd();
            break;
          case "ping" :
            ping_handler(user, args);
            break;
          case "who" :
            who_handler(user, args);
            break;
          case "part" :
            part_handler(user, args);
            break;
          case "list" :
            list_handler(user);
            break;
          default :
            unknown_command_handler(user, args);
            break;
        }
      }
    }
    public void list_handler(User user) {
      if (!user.registered) {
        user.fire_numeric(ERR_NOTREGISTERED);
        return;
      }
      user.fire_numeric(RPL_LISTSTART);
      foreach(Channel k in server.channellist.values) {
        user.fire_numeric(RPL_LIST, k.name, k.users.length(), k.topic);
      }
      user.fire_numeric(RPL_LISTEND);
    }
    public void part_handler(User user, string[] args) {
      if (!user.registered) {
        user.fire_numeric(ERR_NOTREGISTERED);
        return;
      }
      StringBuilder builder = new StringBuilder();
      string msg;
      if (args.length > 2) {
        builder.append(assemble(2,args));
        if (builder.str.has_prefix(":")) {
          builder.erase(0,1);
        }
        msg = builder.str;
      } else {
        msg = null;
      }
      Channel chan = server.get_channel_by_name(args[1]);
      user.part(chan, msg);
    }
    public void who_handler(User user, string[] args) {
      if (!user.registered) {
        user.fire_numeric(ERR_NOTREGISTERED);
        return;
      }
      int i;
      for (i = 1; i < args.length; i++) {
        Channel chan = server.get_channel_by_name(args[i]);
        if (chan.users.length() > 0) {
          chan.who_response(user);
        }
      }
    }
    public string assemble(int position, string[] args) {
      int i;
      StringBuilder builder = new StringBuilder();
      for (i=position;i<args.length;i++) {
        builder.append(args[i]);
        builder.append(" ");
      }
      return builder.str.strip();
    }
    public void quit_handler(User user, string[] args) {
      if (args.length < 2) {
        user.quit(null);
      } else {
        StringBuilder builder = new StringBuilder();
        builder.append(assemble(1,args));
        if (builder.str.has_prefix(":")) {
          builder.erase(0,1);
        }
        user.quit(builder.str);
      }
    } 
    public void ping_handler(User user, string[] args) {
      user.send_line("PONG %s".printf(args[1]));
    }
    public void unknown_command_handler(User user, string[] args) {
      user.fire_numeric(ERR_UNKNOWNCOMMAND, args[0]);
    }
    public void join_handler(User user, string[] args) {
      if (!user.registered) {
        user.fire_numeric(ERR_NOTREGISTERED);
        return;
      }
      if (args.length < 2) {
        user.fire_numeric(ERR_NEEDMOREPARAMS, "JOIN");
        return;
      }
      if (!valid_chan_name(args[1])) {
        user.fire_numeric(ERR_NOSUCHCHANNEL, args[1]);
        return;
      }
      Channel chan = server.get_channel_by_name(args[1]);
      user.join(chan);
    }
    public void privmsg_handler(User user, string[] args) {
      if (!user.registered) {
        user.fire_numeric(ERR_NOTREGISTERED);
        return;
      }
      /*
       * No plans to support sending to hostmasks for now.
       */
      if (args.length < 2) {
        //todo ERR_NORECIPIENT
      } else if (args.length < 3) {
        //todo ERR_NOTEXTTOSEND
      } else {
        if (valid_chan_name(args[1])) {
          //looks like we're targetting a channel.
          StringBuilder builder = new StringBuilder();
          int i;
          for (i=2;i<args.length;i++) {
            builder.append(args[i]);
            builder.append(" ");
          }
          if (builder.str.has_prefix(":")) {
            builder.erase(0,1);
          }
          string msg = builder.str.strip();
          Channel chan = server.get_channel_by_name(args[1]);
          chan.privmsg(user, msg);
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
    public async void process_user (SocketConnection conn) {
      if (server.userlist.size > server.config.max_users && server.config.max_users > 0) {
        try {
          conn.get_socket().close();
        } catch (Error e) {
          server.log(e.message);
        }
        server.log("Max amount of connections %d reached, closing socket".printf(server.config.max_users));
        return;
      }
      User user = new User(conn, server);
      server.userlist[user.id] = user;
      if (server.userlist.size > server.max_users) {
        server.max_users = server.userlist.size;
        server.log("New max amount of users: %d".printf(server.max_users));
      }
      var socket = user.sock.get_socket();
      while (socket.is_connected()) {
        try {
          string msg = yield user.dis.read_line_async (Priority.DEFAULT);
          route(user, msg);
        } catch (Error e) {
          server.log("Encountered error reading socket: %s".printf(e.message));
          user.quit(null);
          break;
        }
      }
    }
    public bool valid_chan_name (string chan) {
      bool valid = true;
      bool has_prefix = false;
      /*
         Checking if a channel is valid:
         1. check if it has a valid prefix as defined in constants.vala
         2. check if it has any forbidden characters as in constants.vala
         3. combine the previous factors, along with checking if there's already a channel by the name.
       */
      foreach (string k in Constants.chan_prefixes) { //step 1
        if (chan.has_prefix(k)) {
          server.log (@"channel name $chan has valid prefix $k");
          has_prefix = true;
          break;
        }
      }
      foreach (string k in Constants.chan_forbidden) { //step 2
        if (k in chan) {
          server.log(@"channel name $chan has invalid char $k");
          valid = false;
          break;
        } 
      }
      if (has_prefix && valid) {
        return true;
      } else {
        return false;
      }
    }
  }
}
