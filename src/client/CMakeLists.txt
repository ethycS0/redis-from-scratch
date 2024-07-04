add_executable(Client start-client.cpp client.cpp)

target_include_directories(Client PRIVATE ../common)
target_include_directories(Client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(Client PRIVATE ../common/helper.cpp)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")