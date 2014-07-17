using Gee;

namespace yrcd {
  void main() {
    var server = new yrcd_server();
    server.log("Created server object");
    server.add_port(6667);
    server.log("Initializing server");
    server.init();
    server.log("For some reason, we're all done here.... goodbye");
  }
}
