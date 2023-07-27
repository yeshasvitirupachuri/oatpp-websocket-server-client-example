cmake_minimum_required(VERSION 3.20)

set(project_name oatpp-websocket-examples)

project(${project_name})

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

find_package(oatpp              1.3.0 REQUIRED)
find_package(oatpp-websocket    1.3.0 REQUIRED)

add_subdirectory(server)
add_subdirectory(client)