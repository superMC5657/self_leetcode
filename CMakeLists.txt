cmake_minimum_required(VERSION 3.5.1)
project(self_leetcode)
set(CMAKE_CXX_STANDARD 14)

include_directories(include)
message(STATUS "leoox src dir = ${CMAKE_SOURCE_DIR}")
message(STATUS "leoox binary dir = ${CMAKE_BINARY_DIR}")
add_executable(1-100 scripts/leetcode1-100/main.cpp)