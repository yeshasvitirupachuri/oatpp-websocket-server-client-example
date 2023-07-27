# oatpp websocket server & client c++ examples

Original C++ [oatpp websocket examples](https://github.com/oatpp/example-websocket) are implemented through `OATPP_CREATE_COMPONENT` and `OATPP_COMPONENT` macros,
that are part of oatpp Dependency Injection (DI) framework [reference](https://oatpp.io/api/latest/oatpp/core/macro/component/).

The code structure of the examples with `_COMPONENT` macros if unclear to new users and a bit obscure about setting up the server and connection handlers using oatpp.
This repo contains refectored c++ examples of server and client without using dependency injection framework macros components.
