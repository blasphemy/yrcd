using Gee;

namespace yrcd {
  class yrcd_numeric_wrapper : Object {
    public HashMap<int,string> numerics = new HashMap<int,string>();
    public enum Num {
      RPL_WELCOME = 001,
      RPL_YOURHOST = 002,
      RPL_CREATED = 003,
      RPL_MYINFO = 004,
      ERR_NONICKNAMEGIVEN = 431,
      ERR_ERRONEOUSNICKNAME = 432,
      ERR_NICKNAMEINUSE = 433;
    }
    public yrcd_numeric_wrapper()   {
      numerics[Num.RPL_WELCOME] = "Welcome to the Internet Relay Network %s!%s@%s";
      numerics[Num.RPL_YOURHOST] = "Your host is %s, running %s version %s";
      numerics[Num.RPL_CREATED] = "This server was created %s";
      numerics[Num.RPL_MYINFO] = "%s %s %s %s";
      numerics[Num.ERR_NONICKNAMEGIVEN] = "No nickname given";
      numerics[Num.ERR_NICKNAMEINUSE] = "%s :Nickname is already in use";
      numerics[Num.ERR_ERRONEOUSNICKNAME] = "%s :Erroneous nickname";
    }
  }
}
