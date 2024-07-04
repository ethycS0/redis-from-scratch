cmake_minimum_required(VERSION 3.10)
project(redis-from-scratch)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CMAKE_STANDARD_REQUIRED True)

add_subdirectory(src/server)
add_subdirectory(src/client)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")