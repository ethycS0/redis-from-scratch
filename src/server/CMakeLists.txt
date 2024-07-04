add_executable(Server start-server.cpp server.cpp protocol.cpp)

target_include_directories(Server PRIVATE ../common)
target_include_directories(Server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(Server PRIVATE ../common/helper.cpp)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")