cmake_minimum_required(VERSION 3.10)

project(vincent)

# warning flags
# all warning message specified here will not be allowed in code
set(WARNING "-Wall -Werror -Wpedantic -Wextra -Wconversion -Wshadow=local")

# c++ version
set(CXX_VERSION "-std=c++17")

# other common compile falgs
set(OTHER_COMPILE_FLAGS "-fexceptions")

# default c++ compile flags
set(COMMON_COMPILE_FLAGS "${WARNING} ${OTHER_COMPILE_FLAGS} ${CXX_VERSION}")

# debug compile flags
set(CMAKE_CXX_FLAGS_DEBUG   "-g -O0 ${COMMON_COMPILE_FLAGS}")

# release compile flags
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2 ${COMMON_COMPILE_FLAGS}")

# default c++ compile flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")

# print compile flags
if("${CMAKE_BUILD_TYPE}" STREQUAL Debug)
  message("debug compile flags: ${CMAKE_CXX_FLAGS_DEBUG}")
elseif("${CMAKE_BUILD_TYPE}" STREQUAL Release)
  message("release compile flags: ${CMAKE_CXX_FLAGS_RELEASE}")
else()
  message("default to debug compile flags: ${CMAKE_CXX_FLAGS}")
endif()

# make sure `make` can print verbose compile info
set(CMAKE_VERBOSE_MAKEFILE ON)

# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

# enable CTest
include(CTest)
enable_testing()

# add app and lib
add_subdirectory(src)

