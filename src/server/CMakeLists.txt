add_executable(Server start-server.cpp server.cpp)

target_include_directories(Server PRIVATE ../common)
target_include_directories(Server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(Server PRIVATE ../common/helper.cpp)