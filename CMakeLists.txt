cmake_minimum_required(VERSION 3.5.1)
project(self_leetcode)
set(CMAKE_CXX_STANDARD 14)

include_directories(include)

#add_compile_options(-std=c++11)
#message(STATUS "optional:-std=c++11")

#set(CMAKE_C_COMPILER  "F:/ProgramData/mingw64/bin/gcc.exe ")
#set(CMAKE_CXX_COMPILER "F:/ProgramData/mingw64/bin/g++.exe ")

#message
message(STATUS "gcc = ${CMAKE_C_COMPILER} ")
message(STATUS "g++ = ${CMAKE_CXX_COMPILER}  ")
message(STATUS "gcc version = ${CMAKE_C_COMPILER_VERSION} ")
message(STATUS "g++ version = ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "leoox src dir = ${CMAKE_SOURCE_DIR}")
message(STATUS "leoox binary dir = ${CMAKE_BINARY_DIR}")


#executable
add_executable(1-100 scripts/leetcode1-100/0_main.cpp)
add_executable(mutil-threads scripts/mutil-threads/0_main.cpp)
add_executable(dp scripts/dp/0_main.cpp)
add_executable(tree scripts/tree/0_main.cpp)
add_executable(graph scripts/graph/0_main.cpp)
add_executable(week_race scripts/week_race/0_main.cpp)
add_executable(hash_map scripts/hash_map/0_main.cpp)
add_executable(backtrack scripts/backtrackingAlgorithm/0_main.cpp)
add_executable(help_others help_others/lj/1.cpp)