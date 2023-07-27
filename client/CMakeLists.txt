cmake_minimum_required(VERSION 3.20)

set(project_name oatpp-websocket-client)

project(${project_name})

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_library(${project_name}-lib
        src/WSListener.cpp
        src/WSListener.hpp
)

## link libs
find_package(oatpp              1.3.0 REQUIRED)
find_package(oatpp-websocket    1.3.0 REQUIRED)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-websocket
)

## add executables
add_executable(${project_name}-exe
        src/App.cpp
)
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)
