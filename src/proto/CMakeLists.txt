project(libproto)

INCLUDE(FindProtobuf)

FIND_PACKAGE(Protobuf REQUIRED)

INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})

file(GLOB proto_src 
"*.proto")

PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER ${proto_src})

# add library
add_library(proto ${PROTO_HEADER} ${PROTO_SRC})