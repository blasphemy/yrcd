using Gee;

namespace yrcd {
	class yrcd_channel : Object {
		public string name;
		public string[] modes;
		public HashMap<int,yrcd_user> users = new HashMap<int,yrcd_user>();
		public void add_user(yrcd_user user) {
      users[user.id] = user;
      foreach (yrcd_user k in users) {
        string msg = ":%s JOIN %s".printf(user.get_hostmask(), this.name);
        k.send_line(msg);
      }
		}
	}
}
