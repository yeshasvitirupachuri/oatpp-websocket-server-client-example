
#include "WSListener.hpp"

#include "oatpp-websocket/WebSocket.hpp"
#include "oatpp-websocket/Connector.hpp"

#include "oatpp/network/tcp/client/ConnectionProvider.hpp"

#include <thread>

#include <iostream>
#include <string>

static std::string client_name{};

namespace {

  const char* TAG = "oatpp-websocket-client";

  bool finished = false;

  void socketTask(const std::shared_ptr<oatpp::websocket::WebSocket>& websocket) {
    websocket->listen();
    OATPP_LOGD(TAG, "SOCKET CLOSED!!!");
    finished = true;
  }

}

void run() {

  OATPP_LOGI(TAG, " Application started");

  auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({"localhost", 8000});

  auto connector = oatpp::websocket::Connector::createShared(connectionProvider);

  auto connection = connector->connect("oatpp-websocket-server");

  OATPP_LOGI(TAG, " Connected");

  auto socket = oatpp::websocket::WebSocket::createShared(connection, true /* maskOutgoingMessages must be true for clients */);

  std::mutex socketWriteMutex;

  socket->setListener(std::make_shared<WSListener>(socketWriteMutex));

  std::thread thread(socketTask, socket);

  while(!finished) {
    {
      std::lock_guard<std::mutex> lock(socketWriteMutex);

      std::string msg = client_name + " says hello";
      std::string log_msg = " sending message [" + msg + "]";
      socket->sendOneFrameText(msg);
      OATPP_LOGD(TAG, log_msg.c_str());
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  thread.join();

}

int main(int argc, char** argv) {

  if(argc < 2)
  {
    std::cerr << "Start the client with name input argument, e.g., ./oatpp-websocket-client-exe Client#20\n";
    return -1;
  }

  client_name = argv[1];

  oatpp::base::Environment::init();
  
  run();
  
  oatpp::base::Environment::destroy();
  
  return 0;
}
