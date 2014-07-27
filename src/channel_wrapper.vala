namespace yrcd {
  public class yrcd_channel_wrapper : GLib.Object {
    public GLib.List<yrcd_channel> chan_list;

    public bool valid_chan_name (string chan) {
      bool valid = true;
      bool has_prefix = false;
      /*
         Checking if a channel is valid:
         1. check if it has a valid prefix as defined in constants.vala
         d. check if it has any forbidden characters as in constants.vala
         3. combine the previous factors, along with checking if there's already a channel by the name.
       */
      foreach (string k in yrcd_constants.chan_prefixes) { //step 1
        if (chan.has_prefix(k)) {
          has_prefix = true;
          break;
        }
      }
      foreach (string k in yrcd_constants.chan_forbidden) { //step 2
        if (k in chan) {
          valid = false;
          break;
        } 
      }
      if (has_prefix && valid && get_channel_by_name(chan) == null) { //step 3
        valid = true;
      } else {
        valid = false;
      }
      return valid;
    }
    public yrcd_channel? get_channel_by_name(string nametocheck) {
      foreach (yrcd_channel k in chan_list) {
        if (k.name.down() == nametocheck.down()) {
          return k;
        }
      }
      //Nothing found, so return null. This is useful in other functions to find if a channel exists by that name at all.
      return null;
    }
  }
}
