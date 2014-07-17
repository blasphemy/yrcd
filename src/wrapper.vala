namespace yrcd {
  public class DelegateWrapper {
    public delegate void DelegateType();
    public DelegateType d;
    public DelegateWrapper(DelegateType d) {
      this.d = d;
    } 
  }
}
