# common library
link_libraries(dl pthread)

# add third party include path
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/include")

# for proto headers, *.pb.h
# some IDE willl use different path for building
set(DEFAULT_BUILD_DIR "${PROJECT_SOURCE_DIR}/build")
if(EXISTS ${DEFAULT_BUILD_DIR})
    message("default build path ${DEFAULT_BUILD_DIR} will be used as build directory")
    include_directories(${DEFAULT_BUILD_DIR})
else()
    message("${CMAKE_BINARY_DIR} will be used as build directory")
    include_directories(${CMAKE_BINARY_DIR})
endif()

# output path
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")

# copy default configuration file
set(IN_CONIFG_FILE "${CMAKE_CURRENT_SOURCE_DIR}/.vincent.ini")
set(OUT_CONFIG_FILE "${CMAKE_BINARY_DIR}/.vincent.ini")
configure_file(${IN_CONIFG_FILE} ${OUT_CONFIG_FILE} COPYONLY)

# copy external libraries
# set(EXTERNAL_LIBRARY_PATH "${LIBRARY_OUTPUT_PATH}/3rdparty")
# file(COPY "3rdparty/lib" DESTINATION "${EXTERNAL_LIBRARY_PATH}")

# external library search path
LINK_DIRECTORIES("${EXTERNAL_LIBRARY_PATH}/lib")

add_subdirectory(app)

add_subdirectory(proto)
add_subdirectory(log)
add_subdirectory(config)
add_subdirectory(common)
#add_subdirectory(http)
