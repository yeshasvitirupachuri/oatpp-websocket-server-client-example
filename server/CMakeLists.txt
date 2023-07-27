cmake_minimum_required(VERSION 3.20)

set(target_name oatpp-websocket-server)

include_directories(src)

add_library(${target_name}-lib
        src/controller/WsApiController.hpp
        src/websocket/WSListener.cpp
        src/websocket/WSListener.hpp
)

target_link_libraries(${target_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-websocket
)

add_executable(${target_name}-exe
        src/App.cpp
)

target_link_libraries(${target_name}-exe ${target_name}-lib)
add_dependencies(${target_name}-exe ${target_name}-lib)
