aux_source_directory(. DIR_LIB_SRCS)

#add_subdirectory(../reactor)
include_directories(../reactor)

add_library(Http ${DIR_LIB_SRCS})


#target_link_libraries(${PROJECT_NAME} PRIVATE Reactor)

#set(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG -O0 -lpthread")