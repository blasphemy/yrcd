namespace yrcd {
  void main() {
    Config config  = new Config("yrcd.config");
    if (config.config_error) {
      return;
    }
    MainLoop loop = new MainLoop();
    yrcd_server server = new yrcd_server(config);
    loop.run();
    server.log("For some reason, we're all done here.... goodbye");
  }
}
