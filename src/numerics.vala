using Gee;

namespace yrcd {
  class NumericWrapper : BaseObject {
    public HashMap<int,string> numerics = new HashMap<int,string>();
    public NumericWrapper() {
      numerics[RPL_WELCOME] = "Welcome to the Internet Relay Network %s!%s@%s";
      numerics[RPL_YOURHOST] = "Your host is %s, running %s version %s";
      numerics[RPL_CREATED] = "This server was created %s";
      numerics[RPL_MYINFO] = "%s %s %s %s";
      numerics[RPL_ENDOFWHO] = "%s :End of WHO list";
      numerics[RPL_LISTSTART] = "Channel :Users Name";
      numerics[RPL_LIST] = "%s %d :%s";
      numerics[RPL_LISTEND] = ":End of channel list";
      numerics[RPL_TOPIC] =  "%s :%s";
      numerics[RPL_TOPICWHOTIME] = "%s %s %d";
      numerics[RPL_WHOREPLY] = "%s %s %s %s %s %s %s %s";
      numerics[RPL_NAMEPLY] = "= %s :%s";
      numerics[RPL_ENDOFNAMES] = "%s :End of /NAMES list.";
      numerics[RPL_MOTD] = ":- %s";
      numerics[RPL_MOTDSTART] = ":- %s Message of the day -";
      numerics[RPL_ENDOFMOTD] = ":End of /MOTD command.";
      numerics[ERR_NOSUCHCHANNEL] = "%s :No such channel";
      numerics[ERR_UNKNOWNCOMMAND] = "%s :Unkown command";
      numerics[ERR_NONICKNAMEGIVEN] = "No nickname given";
      numerics[ERR_NICKNAMEINUSE] = "%s :Nickname is already in use";
      numerics[ERR_ERRONEOUSNICKNAME] = "%s :Erroneous nickname";
      numerics[ERR_NOTREGISTERED] = ":You have not registered";
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
  public const int RPL_ENDOFWHO = 315;
  public const int RPL_LISTSTART = 321;
  public const int RPL_LISTEND = 323;
  public const int RPL_LIST = 322;
  public const int RPL_TOPIC = 332;
  public const int RPL_TOPICWHOTIME = 333;
  public const int RPL_WHOREPLY = 352;
  public const int RPL_NAMEPLY = 353;
  public const int RPL_ENDOFNAMES = 366;
  public const int RPL_MOTD = 372;
  public const int RPL_MOTDSTART = 375;
  public const int RPL_ENDOFMOTD = 376;
  public const int ERR_NOSUCHCHANNEL = 403;
  public const int ERR_UNKNOWNCOMMAND = 421;
  public const int ERR_NONICKNAMEGIVEN = 431;
  public const int ERR_ERRONEOUSNICKNAME = 432;
  public const int ERR_NICKNAMEINUSE = 433;
  public const int ERR_NOTREGISTERED = 451;
  public const int ERR_NEEDMOREPARAMS = 461;
  public const int ERR_ALREADYREGISTRED = 462;

}
