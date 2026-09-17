cmake_minimum_required(VERSION 3.16)

project(net VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(net STATIC)

target_include_directories(net PUBLIC include)

target_sources(net PUBLIC
    src/net.cpp
)

add_executable(net_test
    src/main.cpp
)

target_include_directories(net_test PUBLIC include)

target_link_libraries(net_test PUBLIC net)
