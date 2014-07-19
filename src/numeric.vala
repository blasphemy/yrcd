namespace yrcd {
  public class yrcd_numeric : Object {
    public int numeric { get; set; }
    public string code { get; set; }
    public string msg  { get; set; } 

    public yrcd_numeric (int _numeric, string _code, string _msg) {
      numeric = _numeric;
      code = _code;
      msg = _msg;
    }
  }
}
