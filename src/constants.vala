namespace yrcd {
  class Constants : Object {
    public const string version = "0.2";
    public const string software = "yrcd";
    public const string[] cmodes = {};
    public const string[] umodes = {};
    public const string[] forbidden_nick_chars = {":", "#", "&", "%", "@", "+"};
    public const string[] chan_prefixes = {"#", "&"};
    public const string[] chan_forbidden = {":", "&", "@", "%", "+"};
  }
}
