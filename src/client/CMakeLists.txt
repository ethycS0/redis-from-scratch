add_executable(Client start-client.cpp client.cpp)

target_include_directories(Client PRIVATE ../common)
target_include_directories(Client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(Client PRIVATE ../common/helper.cpp)