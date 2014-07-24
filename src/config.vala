namespace yrcd {
  public class yrcd_config : Object {
    private KeyFile file = new KeyFile();
    public string sname { get; set; }
    public yrcd_config(string filepath) {
      file.load_from_file(filepath,KeyFileFlags.NONE);
      file.set_list_separator (',');
      sname = file.get_string("ServerVariables", "server_name");
    }
  }
}