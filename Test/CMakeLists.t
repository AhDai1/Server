cmake_minimum_required(VERSION 2.8)

project(test)

#add_compile_options(-lpthread -O0 -g -Wall)
set(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG -O0 -lpthread")
include_directories(pthread)

include_directories(../reactor ../thread)
aux_source_directory(../reactor SRC_LIST)
aux_source_directory(../thread SRC_LIST1)

add_executable(main main9.cc  ${SRC_LIST} ${SRC_LIST1})