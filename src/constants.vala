namespace yrcd {
	class yrcd_constants : Object {
		public const string version = "0.1";
		public const string software = "yrcd";
		public const string motd = "Welcome!";
		public const string[] listen_ips = {"127.0.0.1"};
		public const string[] cmodes = {};
		public const string[] umodes = {};
		public const string[] forbidden_nick_chars = {":", "#", "&", "%", "@", "+"};
		public const string[] chan_prefixes = {"#", "&"};
	  public const string[] chan_forbidden = {":", "&", "@", "%", "+"};
    public const int64 ping_invertal = 45;
  }
}
