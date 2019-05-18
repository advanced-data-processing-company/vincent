file(GLOB LIB_SRC
    "*.cpp"
    "*.h")

file(GLOB TEST_SRC
    "*test.cpp")

list(REMOVE_ITEM LIB_SRC ${TEST_SRC}})

# add library
add_library(config ${LIB_SRC})
target_link_libraries(config common)

# add test executable
add_executable(config_test ${TEST_SRC})

add_test(config ${EXECUTABLE_OUTPUT_PATH}/config_test)

# link to lib
target_link_libraries(config_test config)
