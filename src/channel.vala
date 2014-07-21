using Gee;

namespace yrcd {
	class yrcd_channel : Object {
		public string name;
		public string[] modes;
		public HashMap<int,yrcd_user> users = new HashMap<int,yrcd_user>();
		public void add_user(yrcd_user user) {
      users[user.id] = user;
		}
	}
}