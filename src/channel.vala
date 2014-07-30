using Gee;

namespace yrcd {
  class yrcd_channel : Object {
    public string name { get; set; } 
    public string[] modes;
    public string topic;
    public int64 epoch;
    public int64 topictime;
    public string topic_host;
    public yrcd_server server;
    public GLib.List<weak yrcd_user> users;
    public uint timer;
    public yrcd_channel(yrcd_server _server, string _name) {
      server = _server;
      set_topic("", server.config.sname);
      epoch = new DateTime.now_utc().to_unix();
      name = _name;
      server.log (@"New channel created $name");
      users = new GLib.List<yrcd_user>();
      check_users();
    }
    public void check_users() {
      timer = Timeout.add_seconds_full(Priority.DEFAULT, 30, () => {
          if (users.length() < 1) {
            server.remove_channel(name);
            Source.remove(timer);
            server.log(@"channel $name has no users, destroying");
            return false;
            } else {
            return true;
            }
          });
    }
    public bool add_user(yrcd_user user) {
      if (users.find(user) != null) {
        string nick = user.nick;
        server.log(@"user $nick attempted to join $name while already joined... doing nothing");
        return false;
      }
      users.append(user);
      foreach (yrcd_user k in users) {
        string msg = ":%s JOIN %s".printf(user.get_hostmask(), this.name);
        k.send_line(msg, Priority.LOW);
      }
      user.fire_numeric(RPL_TOPIC, name, topic);
      user.fire_numeric(RPL_TOPICWHOTIME, name, topic_host, topictime);
      fire_names(user);
      return true;
    }
    public void quit(yrcd_user user, string msg) {
      foreach (yrcd_user k in users) {
        //:danieltest!~k@2604:180::d8f:be0e QUIT :Client Quit
        k.send_line(":%s QUIT :%s".printf(user.get_hostmask(),msg), Priority.LOW);
      }
      users.remove(user);
    }
    public void part(yrcd_user user, string msg) {
      foreach(yrcd_user k in users) {
        k.send_line(":%s PART %s :%s".printf(user.get_hostmask(),name,msg), Priority.LOW);
      }
      users.remove(user);
    }
    public void set_topic(string newtopic, string hostmask) {
      topic = newtopic;
      topic_host = hostmask;
      //topictime = new DateTime.now_utc().to_unix();
    }
    public void fire_names(yrcd_user user) {
      StringBuilder builder = new StringBuilder();
      foreach (yrcd_user k in users) {
        builder.append(k.nick);
        builder.append(" ");
      }
      string resp = builder.str.strip();
      user.fire_numeric(RPL_NAMEPLY, name, resp);
      user.fire_numeric(RPL_ENDOFNAMES, name);
    }
    public void privmsg(yrcd_user user, string msg) {
      string to_send = ":%s PRIVMSG %s :%s".printf(user.get_hostmask(), name, msg);
      server.log(@"channel $name sending message $msg");
      foreach (yrcd_user k in users) {
        if (k != user) {
          k.send_line(to_send, Priority.HIGH);
        }
      }
    }
    public void who_response (yrcd_user user) {
      foreach (yrcd_user k in users) {
        //:presentday.notroll.me 352 test #k ~tyrone atlanta.the-beach.co k.notroll.net Tyrone H :0 Tyrone B. Stoned
        user.fire_numeric(RPL_WHOREPLY, name, k.ident, k.host, server.config.sname, k.nick, "H", ":0", k.realname);
      }
      user.fire_numeric(RPL_ENDOFWHO, name);
    }

  }
}
