aux_source_directory(. DIR_LIB_SRCS)

add_library (Thread ${DIR_LIB_SRCS})

set(CMAKE_CXX_FLAGS_DEBUG "-g -D_DEBUG -O0 -lpthread")