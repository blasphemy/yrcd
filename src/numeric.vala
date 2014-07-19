namespace yrcd {
  public class yrcd_numeric : Object {
    public string numeric { get; set; }
    public string code { get; set; }
    public string msg  { get; set; } 

    public yrcd_numeric (string _numeric, string _code, string _msg) {
      numeric = _numeric;
      code = _code;
      msg = _msg;
    }
  }
}
