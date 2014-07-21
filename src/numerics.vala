using Gee;

namespace yrcd {
  class yrcd_numeric_wrapper : Object {
    public HashMap<int,string> numerics = new HashMap<int,string>();
    public yrcd_numeric_wrapper()   {
      numerics[RPL_WELCOME] = "Welcome to the Internet Relay Network %s!%s@%s";
      numerics[RPL_YOURHOST] = "Your host is %s, running %s version %s";
      numerics[RPL_CREATED] = "This server was created %s";
      numerics[RPL_MYINFO] = "%s %s %s %s";
      numerics[ERR_NONICKNAMEGIVEN] = "No nickname given";
      numerics[ERR_NICKNAMEINUSE] = "%s :Nickname is already in use";
      numerics[ERR_ERRONEOUSNICKNAME] = "%s :Erroneous nickname";
    }
  }

  //define these in the global namespace
  public const int RPL_WELCOME = 001;
  public const int RPL_YOURHOST = 002;
  public const int RPL_CREATED = 003;
  public const int RPL_MYINFO = 004;
  public const int ERR_NONICKNAMEGIVEN = 431;
  public const int ERR_ERRONEOUSNICKNAME = 432;
  public const int ERR_NICKNAMEINUSE = 433;
}
