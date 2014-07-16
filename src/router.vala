namespace yrcd {
  class yrcd_router : Object {
    public void route (yrcd_user user, string msg) {
      user.server.log("Received line %s".printf(strip_end(msg)));
    }
    public string strip_end (string msg) {
      var builder = new StringBuilder ();
      builder.append(msg);
      builder.truncate(builder.len - 1);
      return builder.str;
    }
  }
}
