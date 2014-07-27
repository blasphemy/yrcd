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
    public HashMap<int,yrcd_user> users = new HashMap<int,yrcd_user>();
    public yrcd_channel(yrcd_server _server, string _name) {
      server = _server;
      set_topic("", "system");
      epoch = new DateTime.now_utc().to_unix();
      name = _name;
      server.log (@"New channel created $name");
    }
    public bool add_user(yrcd_user user) {
      foreach (yrcd_user k in users) {
        if (k == user) {
          return false;
        }
      }
      users[user.id] = user;
      foreach (yrcd_user k in users) {
        string msg = ":%s JOIN %s".printf(user.get_hostmask(), this.name);
        k.send_line(msg);
      }
      user.fire_numeric(RPL_TOPIC, name, topic);
      user.fire_numeric(RPL_TOPICWHOTIME, name, topic_host, topictime);
      return true;
    }
    public void set_topic(string newtopic, string hostmask) {
      topic = newtopic;
      topic_host = hostmask;
      //topictime = new DateTime.now_utc().to_unix();
    }
  }
}
