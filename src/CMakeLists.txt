cmake_minimum_required(VERSION 3.10)

project(vicent)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -Werror -Wpedantic -Wextra -ffexceptions -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g -Wall -Werror -Wpedantic -Wextra -ffexceptions -std=c++11")

# common library
link_libraries(dl pthread)

# add third party include path
include_directories(${CMAKE_SOURCE_DIR} "${CMAKE_SOURCE_DIR}/3rdparty")

# for proto headers, *.pb.h
# some IDE willl use different path for building
set(DEFAULT_BUILD_DIR "${CMAKE_SOURCE_DIR}/build")
if(EXISTS ${DEFAULT_BUILD_DIR})
    message("default build path ${DEFAULT_BUILD_DIR} will be used as build directory")
    include_directories(${DEFAULT_BUILD_DIR})
else()
    message("${CMAKE_BINARY_DIR} will be used as build directory")
    include_directories(${CMAKE_BINARY_DIR})
endif()

add_subdirectory(app)

# if your executable need gtest just target_link_libraries(xxx_test gtest)
add_subdirectory(3rdparty/gtest_src)
add_subdirectory(proto)