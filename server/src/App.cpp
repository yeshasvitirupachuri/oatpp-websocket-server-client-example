
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"
#include "oatpp/network/Server.hpp"

#include "./controller/WsApiController.hpp"

#include <iostream>

void run() {

  // Initiate router component
  auto router = oatpp::web::server::HttpRouter::createShared();

  // Add api controller to the http router
  router->addController(std::make_shared<WsApiController>());

  // Initiate http connection handler
  auto http_connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

  // Initiate server connection provider
  auto tcp_serverConnectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({"0.0.0.0", 8000, oatpp::network::Address::IP_4});

  // Initiate server to take handle incoming TCP connections and passes them to HTTP connection handler
  oatpp::network::Server server(tcp_serverConnectionProvider, http_connectionHandler);

  // Priny info about server port
  OATPP_LOGI("oatpp-websocket-server-example", "Server running on port %s", tcp_serverConnectionProvider->getProperty("port").getData());

  // Run server
  server.run();

}

int main(int argc, const char * argv[]) {

  oatpp::base::Environment::init();

  run();

  oatpp::base::Environment::destroy();

  return 0;
}