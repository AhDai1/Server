cmake_minimum_required(VERSION 2.8)

project(test)

#库目录
set(TOP_DIR ${CMAKE_CURRENT_LIST_DIR}/../)

add_definitions("-Wall -g")

#set(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG -O0 -lpthread")
#set_target_properties(${TARGET} PROPERTIES
#COMPILE_FLAGS "-pthread"
#LINK_FLAGS "-pthread")


add_subdirectory(${TOP_DIR}/reactor reactor_binary_dir)
add_subdirectory(${TOP_DIR}/thread thread_binary_dir)
add_subdirectory(${TOP_DIR}/http http_binary_dir)

add_executable(${PROJECT_NAME} WebServer.cc)

target_link_libraries(${PROJECT_NAME} PRIVATE Reactor)
target_link_libraries(${PROJECT_NAME} PRIVATE Thread)
target_link_libraries(${PROJECT_NAME} PRIVATE Http)
target_link_libraries(${PROJECT_NAME} PRIVATE -lpthread)


target_include_directories(${PROJECT_NAME} PRIVATE ${TOP_DIR}/thread)
target_include_directories(${PROJECT_NAME} PRIVATE ${TOP_DIR}/reactor)
target_include_directories(${PROJECT_NAME} PRIVATE ${TOP_DIR}/http)
