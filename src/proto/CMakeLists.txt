project(libproto)

INCLUDE(FindProtobuf)

FIND_PACKAGE(Protobuf REQUIRED)

INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})

file(GLOB proto_src 
    "*.proto")

file(GLOB test_src
    "*.cpp")

PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER ${proto_src})

# add library
add_library(proto ${PROTO_HEADER} ${PROTO_SRC})

# add test executable
add_executable(proto_test ${test_src})

# link to libproto
target_link_libraries(proto_test proto protobuf gtest)
