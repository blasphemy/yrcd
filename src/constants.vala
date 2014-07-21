namespace yrcd {
  class yrcd_constants : Object {
    public const string version = "0.1";
    public const string software = "yrcd";
    public const string motd = "Welcome!";
    public const string[] listen_ips = {"127.0.0.1"};
    public const uint16[] listen_ports = {6667, 6668};
    public const string sname = "test.net.local";
    public const string[] cmodes = {};
    public const string[] umodes = {};
    public const string[] forbidden_nick_chars = {":", "#", "&", "%", "@", "+"};
  }
}
