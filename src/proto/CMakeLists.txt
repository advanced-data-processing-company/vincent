project(libproto)

INCLUDE(FindProtobuf)

FIND_PACKAGE(Protobuf REQUIRED)

INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})

file(GLOB proto_def
    "*.proto")

file(GLOB test_src
    "*.cpp")

PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER ${proto_def})

# add library
add_library(proto ${PROTO_HEADER} ${PROTO_SRC})

# add test executable
add_executable(proto_test ${test_src})
add_test(proto ${EXECUTABLE_OUTPUT_PATH}/proto_test)

# link to libproto
target_link_libraries(proto_test proto protobuf)

# for #include "build/proto/xxx.pb.h"
target_include_directories(proto_test PRIVATE "${CMAKE_BINARY_DIR}/../")
