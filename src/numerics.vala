using Gee;

namespace yrcd {
  class yrcd_numeric_wrapper : Object {
    public HashMap<int,string> numerics = new HashMap<int,string>();
    public yrcd_numeric_wrapper()   {
      numerics[RPL_WELCOME] = "Welcome to the Internet Relay Network %s!%s@%s";
      numerics[RPL_YOURHOST] = "Your host is %s, running %s version %s";
      numerics[RPL_CREATED] = "This server was created %s";
      numerics[RPL_MYINFO] = "%s %s %s %s";
      numerics[RPL_TOPIC] =  "%s :%s";
      numerics[RPL_TOPICWHOTIME] = "%s %s %s";
      numerics[RPL_MOTD] = ":- %s";
      numerics[RPL_MOTDSTART] = ":- %s Message of the day -";
      numerics[RPL_ENDOFMOTD] = ":End of /MOTD command.";
      numerics[ERR_UNKNOWNCOMMAND] = "%s :Unkown command";
      numerics[ERR_NONICKNAMEGIVEN] = "No nickname given";
      numerics[ERR_NICKNAMEINUSE] = "%s :Nickname is already in use";
      numerics[ERR_ERRONEOUSNICKNAME] = "%s :Erroneous nickname";
      numerics[ERR_NEEDMOREPARAMS] = "%s :Not enough parameters";
      numerics[ERR_ALREADYREGISTRED] = "You may not reregister";
    }
  }
  /*
      Numerics are purposely defined in the global namespace.
      the reasoning behind this is to make the syntax when firing numerics easier.
      Ex: user.fire_numeric(ERR_ALREADYREGISTERED).
      Easy.
  */
  public const int RPL_WELCOME = 001;
  public const int RPL_YOURHOST = 002;
  public const int RPL_CREATED = 003;
  public const int RPL_MYINFO = 004;
  public const int RPL_TOPIC = 332;
  public const int RPL_TOPICWHOTIME = 333;
  public const int RPL_MOTD = 372;
  public const int RPL_MOTDSTART = 375;
  public const int RPL_ENDOFMOTD = 376;
  public const int ERR_UNKNOWNCOMMAND = 421;
  public const int ERR_NONICKNAMEGIVEN = 431;
  public const int ERR_ERRONEOUSNICKNAME = 432;
  public const int ERR_NICKNAMEINUSE = 433;
  public const int ERR_NEEDMOREPARAMS = 461;
  public const int ERR_ALREADYREGISTRED = 462;

}
