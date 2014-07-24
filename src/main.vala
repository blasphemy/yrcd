namespace yrcd {
  void main() {
  	yrcd_config config  = new yrcd_config("yrcd.config");
    yrcd_server server = new yrcd_server(config);
    server.log("For some reason, we're all done here.... goodbye");
  }
}
