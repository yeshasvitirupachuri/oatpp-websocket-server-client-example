# oatpp websocket server & client c++ examples

Original C++ [oatpp websocket examples](https://github.com/oatpp/example-websocket) are implemented through `OATPP_CREATE_COMPONENT` and `OATPP_COMPONENT` macros,
that are part of oatpp Dependency Injection (DI) framework [reference](https://oatpp.io/api/latest/oatpp/core/macro/component/).

The code structure of the examples with `_COMPONENT` macros if unclear to new users and a bit obscure about setting up the server and connection handlers using oatpp.
This repo contains refectored c++ examples of server and client without using dependency injection framework macros components.

### Dependencies Installation

- [oatpp release 1.3.0](https://github.com/oatpp/oatpp/releases/tag/1.3.0)
- [oatpp-websocket release 1.3.0](https://github.com/oatpp/oatpp-websocket/releases/tag/1.3.0)

###### oatpp

```
git clone https://github.com/oatpp/oatpp
cd oatpp
git checkout tags/1.3.0
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=<path-to-oatpp>/build/install
make all
make install
```

###### oatpp-websocket

```
git clone https://github.com/oatpp/oatpp-websockete
cd oatpp
git checkout tags/1.3.0
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=<path-to-oatpp-websocket>/build/install
make all
make install
```

### Building

```
git clone https://github.com/yeshasvitirupachuri/oatpp-websocket-server-client-example
cd oatpp-websocket-server-client-example
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -Doatpp_DIR=<path-to-oatpp>/build/install/lib/cmake/oatpp-1.3.0/ -Doatpp-websocket_DIR=<path-to-oatpp-websocket>/build/install/lib/cmake/oatpp-websocket-1.3.0/
make all
```

#### Running Server & Client

- Open a new terminal and go to the repo root directory

##### Server

`./build/server/oatpp-websocket-server-exe`

- The server status can be checked by opening the following address in a web browser

`http://localhost:8000/`

![](./misc/server_root.png)


##### Client

- The client application needs an extra argument that is taken as the client name. In a new terminal run the client executable

`./build/client/oatpp-websocket-client-exe Client#1`
