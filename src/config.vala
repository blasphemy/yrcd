namespace yrcd {
  public class Config : Object {
    private KeyFile file = new KeyFile();
    public string sname { get; set; }
    public List<uint16> listen_ports;
    public string[] listen_ips;
    public List<string> motd;
    public int ping_invertal;
    public int max_users;
    public bool config_error = false;
    public bool cloaking;
    public string salt;
    public Config(string filepath) {
      try {
        file.load_from_file(filepath,KeyFileFlags.NONE);
        file.set_list_separator (',');
        sname = file.get_string("ServerVariables", "server_name");
        int[] tmplist = file.get_integer_list("Networking", "listening_ports");
        foreach (int k in tmplist) {
          listen_ports.append((uint16) k);
        }
        listen_ips = file.get_string_list("Networking", "listening_ips");
        string motdpath = file.get_string("ServerVariables","motd_path");
        var motdfile = File.new_for_path(motdpath);
        var dis = new DataInputStream(motdfile.read());
        string motd_line;
        while ((motd_line = dis.read_line(null)) != null) {
          motd.append(motd_line);
        }
        ping_invertal = file.get_integer("ServerVariables", "ping_invertal");
        salt = file.get_string("ServerVariables","host_salt");
        cloaking = file.get_boolean("ServerVariables","cloaking");
        if (file.has_key("ServerVariables", "max_connections")) {
            max_users = file.get_integer("ServerVariables", "max_connections");
        } else {
            max_users = 0;
        }
      } catch (Error e) {
        stdout.printf("Error Loading config file: %s\n".printf(e.message));
        config_error = true;
      }
    }
  }
}
