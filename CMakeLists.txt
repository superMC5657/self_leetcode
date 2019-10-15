cmake_minimum_required(VERSION 3.5.1)
project(self_leetcode)
set(CMAKE_CXX_STANDARD 14)

include_directories(include)

#message
message(STATUS "gcc = ${CMAKE_C_COMPILER} ")
message(STATUS "g++ = ${CMAKE_CXX_COMPILER}  ")
message(STATUS "leoox src dir = ${CMAKE_SOURCE_DIR}")
message(STATUS "leoox binary dir = ${CMAKE_BINARY_DIR}")

add_executable(1-100 scripts/leetcode1-100/0_main.cpp)
add_executable(mutil-threads scripts/mutil-threads/0_main.cpp)
add_executable(dp scripts/dp/0_main.cpp)
add_executable(tree scripts/tree/0_main.cpp)
add_executable(graph scripts/graph/0_main.cpp)
add_executable(week_race scripts/week_race/0_main.cpp)