file(GLOB LIB_SRC
    "*.cpp"
    "*.h")

file(GLOB TEST_SRC
    "*test.cc")

list(REMOVE_ITEM LIB_SRC ${TEST_SRC}})

# add library
add_library(ws_server ${LIB_SRC})

# add test executable
add_executable(ws_server_test ${TEST_SRC})

add_test(ws_server_test ${EXECUTABLE_OUTPUT_PATH}/ws_server_test)

# link to lib
target_link_libraries(ws_server_test "-Wl,--whole-archive" ws_server "-Wl,--no-whole-archive" common log)
