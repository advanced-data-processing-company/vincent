cmake_minimum_required(VERSION 3.10)

project(vicent)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -Werror -Wpedantic -Wextra -ffexceptions -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g -Wall -Werror -Wpedantic -Wextra -ffexceptions -std=c++11")
set(COMMON_LIB dl pthread)

add_subdirectory(app)