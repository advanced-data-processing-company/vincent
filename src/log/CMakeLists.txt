file(GLOB LIB_SRC
    "*.cpp"
    "*.h")

file(GLOB TEST_SRC
    "*test.cpp")

list(REMOVE_ITEM LIB_SRC ${TEST_SRC}})

# add library
add_library(log ${LIB_SRC})

# add test executable
add_executable(log_test ${TEST_SRC})

add_test(log ${EXECUTABLE_OUTPUT_PATH}/log_test)

# link to lib
target_link_libraries(log_test log common)
