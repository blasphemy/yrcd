namespace yrcd {
  void main() {
    var server = new yrcd_server();
    server.log("Initialized server....");
    server.add_port(6667);
    server.log("Added port 6667 to server.");
    server.init();
    server.log("For some reason, we're all done here.... goodbye");
  }
}
