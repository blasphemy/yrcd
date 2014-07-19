using Gee;

namespace yrcd {
  class yrcd_numeric_wrapper : Object {
    public HashMap<string,yrcd_numeric> numerics = new HashMap<string,yrcd_numeric>();

    public yrcd_numeric_wrapper() {
      register_numeric("RPL_WELCOME",  "001", "Welcome to the Internet Relay Network %s!%s@%s");
      register_numeric("RPL_YOURHOST", "002", "Your host is %s, running version %s");
      register_numeric("RPL_CREATED",  "003", "This server was created %s");
      register_numeric("RPL_MYINFO",   "004", "%s %s %s %s");
    }
    private void register_numeric (string code, string numeric, string msg) {
      numerics[code] = new yrcd_numeric(numeric,code,msg);
    }
  }
}
