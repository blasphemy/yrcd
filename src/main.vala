namespace yrcd {
  void main() {
    var server = new yrcd_server();
    server.log("Created server object");
    server.log("Initializing server: %s %s".printf(server.consts.software, server.consts.version));
    server.init();
    server.log("For some reason, we're all done here.... goodbye");
  }
}
