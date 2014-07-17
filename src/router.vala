namespace yrcd {
  class yrcd_router : Object {
    public void route (yrcd_user user, string msg) {
      string stripped = strip_end(msg);
      string[] args = tokenize(stripped);
      user.server.log("USER %d: received line %s".printf(user.id,stripped));
      if (args[0] == "QUIT") {
        user.server.log("Received QUIT");
        user.quit(null);
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
