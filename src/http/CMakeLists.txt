file(GLOB LIB_SRC
    "*.cpp"
    "*.h")

file(GLOB TEST_SRC
   "*test.cpp")

#list(REMOVE_ITEM ${LIB_SRC})

# add library
add_library(http ${LIB_SRC})

message("----" ${LIB_SRC})
# add test executable
add_executable(clientinterface_test ${TEST_SRC}
    )

add_test(http ${EXECUTABLE_OUTPUT_PATH}/http_test)

# link to lib
target_link_libraries(clientinterface_test http common http_parser)
