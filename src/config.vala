namespace yrcd {
  public class yrcd_config : Object {
    private KeyFile file = new KeyFile();
    public string sname { get; set; }
    public List<uint16> listen_ports;
    public string[] listen_ips;
      public yrcd_config(string filepath) {
        try {
          file.load_from_file(filepath,KeyFileFlags.NONE);
          file.set_list_separator (',');
          sname = file.get_string("ServerVariables", "server_name");
          int[] tmplist = file.get_integer_list("Networking", "listening_ports");
          foreach (int k in tmplist) {
            uint16 j;
            for (j=0;j<k;) {
              j++;
            } //Could not get it to cast from int to uint16 so I'm taking this ghetto approach.
            listen_ports.append(j);
          }
          listen_ips = file.get_string_list("Networking", "listening_ips");
        } catch (Error e) {
          error("Error reading config file: %s".printf(e.message));
        }
      }
  }
}
