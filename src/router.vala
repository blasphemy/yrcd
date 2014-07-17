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
      user.server.log("USER %d: received line %s".printf(user.id,stripped));
      switch (args[0]) {
        case "quit" :
          user.server.log("Received QUIT");
          user.quit(null);
          break;
        case "nick" :
          user.change_nick(args);
          break;
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
