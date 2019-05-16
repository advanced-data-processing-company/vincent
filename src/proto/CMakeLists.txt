project(libproto)

FIND_PACKAGE(Protobuf REQUIRED)

if(PROTOBUF_FOUND)
    message("protobuf found version:${Protobuf_VERSION}")
    message("PROTOBUF_INCLUDE_DIR is : ${PROTOBUF_INCLUDE_DIR}")
    message("Protobuf_PROTOC_EXECUTABLE is ${Protobuf_PROTOC_EXECUTABLE}")
    if(Protobuf_VERSION VERSION_GREATER_EQUAL "3.7.1")
        message("protobuf is OK")
        set(PROTOBUF_OK ON)
    else()
        message("protobuf version is too low")
        set(PROTOBUF_OK OFF)
    endif()
else()
    set(PROTOBUF_OK OFF)
endif()

# /usr/local

if(NOT PROTOBUF_OK)
    message("use protobuf of self built version")
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/include/google" DESTINATION "${CMAKE_BINARY_DIR}/include-1")
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/bin/protoc" DESTINATION "${CMAKE_BINARY_DIR}/bin-1/")
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/lib/libprotobuf.so.18.0.1" DESTINATION "${CMAKE_BINARY_DIR}/lib-1/")
else()
    message("use protobuf of pre-installed version")
endif()

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
