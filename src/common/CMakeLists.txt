file(GLOB LIB_SRC
    "*.cpp"
    "*.h")

file(GLOB TEST_SRC
    "*test.cpp")

list(REMOVE_ITEM LIB_SRC ${TEST_SRC}})

# add library
add_library(common ${LIB_SRC})

# add test executable
add_executable(common_test ${TEST_SRC})

add_test(common ${EXECUTABLE_OUTPUT_PATH}/common_test)

# link to lib
target_link_libraries(common_test common)
