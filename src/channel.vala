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
    public GLib.List<yrcd_user> users;
    public yrcd_channel(yrcd_server _server, string _name) {
      server = _server;
      set_topic("", server.config.sname);
      epoch = new DateTime.now_utc().to_unix();
      name = _name;
      server.log (@"New channel created $name");
      users = new GLib.List<yrcd_user>();
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
        k.send_line(msg);
      }
      user.fire_numeric(RPL_TOPIC, name, topic);
      user.fire_numeric(RPL_TOPICWHOTIME, name, topic_host, topictime);
      fire_names(user);
      return true;
    }
    public void quit(yrcd_user user, string msg) {
      foreach (yrcd_user k in users) {
        //:danieltest!~k@2604:180::d8f:be0e QUIT :Client Quit
        k.send_line(":%s QUIT :%s".printf(user.get_hostmask(),msg));
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
          k.send_line(to_send);
        }
      }
    }

  }
}
