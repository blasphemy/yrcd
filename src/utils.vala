namespace yrcd {
  namespace Utils {
    public string secure_hash (string in, string salt = "") {
      StringBuilder builder = new StringBuilder();
      //hash the input data with salt
      builder.append(GLib.Checksum.compute_for_string(ChecksumType.MD5,in + salt));
      //make it longer if needed
      while (builder.str.length < in.length) {
        builder.append(GLib.Checksum.compute_for_string(ChecksumType.MD5,builder.str));
      }
      //and shorten it to the original length.
      builder.truncate(in.length);
      return builder.str;
    }
  }
}
