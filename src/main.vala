namespace yrcd {
  void main() {
    yrcd_config config  = new yrcd_config("yrcd.config");
    if (config.config_error) {
      return;
    }
    MainLoop loop = new MainLoop();
    yrcd_server server = new yrcd_server(config);
    loop.run();
    server.log("For some reason, we're all done here.... goodbye");
  }
}
