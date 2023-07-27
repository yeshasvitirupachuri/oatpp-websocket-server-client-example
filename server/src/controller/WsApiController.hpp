
#ifndef WsApiController_hpp
#define WsApiController_hpp


#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp-websocket/ConnectionHandler.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "websocket/WSListener.hpp"

#include "oatpp-websocket/Handshaker.hpp"


auto static objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

#include OATPP_CODEGEN_BEGIN(ApiController) //<-- codegen begin

/**
 * Controller with WebSocket-connect endpoint.
 */
class WsApiController : public oatpp::web::server::api::ApiController {
private:
  std::shared_ptr<oatpp::websocket::ConnectionHandler> websocket_ConnectionHandler;

public:
  WsApiController()
    : oatpp::web::server::api::ApiController(objectMapper)
  {
    websocket_ConnectionHandler = oatpp::websocket::ConnectionHandler::createShared();
    websocket_ConnectionHandler->setSocketInstanceListener(std::make_shared<WSInstanceListener>());
  }
public:
  
  ENDPOINT("GET", "/", root) {

    const char* pageTemplate =
      "<html lang='en'>"
        "<head>"
          "<meta charset=utf-8/>"
        "</head>"
        "<body>"
          "<p>Hello Multithreaded WebSocket Server!</p>"
          "<p>"
            "<code>websocket endpoint is: localhost:8000/oatpp-websocket-server</code>"
          "</p>"
        "</body>"
      "</html>";

    return createResponse(Status::CODE_200, pageTemplate);
    
  };

  ENDPOINT("GET", "oatpp-websocket-server", ws, REQUEST(std::shared_ptr<IncomingRequest>, request)) {
    return oatpp::websocket::Handshaker::serversideHandshake(request->getHeaders(), websocket_ConnectionHandler);
  };
  
};

#include OATPP_CODEGEN_END(ApiController) //<-- codegen end

#endif /* WsApiController_hpp */
