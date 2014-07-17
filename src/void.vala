//...

namespace yrcd {
  public delegate void VoidFunc();

  public class VoidFuncData {
    public VoidFunc func;

    public VoidFuncData (owned VoidFunc func) {
      this.func = (owned) func;
    }
  }
}
