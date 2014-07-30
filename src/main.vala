namespace yrcd {
  void main() {
    Config config  = new Config("yrcd.config");
    if (config.config_error) {
      return;
    }
    MainLoop loop = new MainLoop();
    Server server = new Server(config);
    loop.run();
    server.log("For some reason, we're all done here.... goodbye");
  }
}
