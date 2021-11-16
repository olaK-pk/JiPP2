cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD  14)

include_directories(include)

add_library(lib STATIC src/lib.cpp)
