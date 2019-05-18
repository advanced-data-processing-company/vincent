file(GLOB HTTP_SRC 
    "*[^http].cpp"
    "*[^http].h")

file(GLOB HTTP_TEST_SRC
    "*http.cpp")

# add library
add_library(http ${HTTP_SRC})

# add test executable
add_executable(http_test ${HTTP_TEST_SRC})

add_test(http ${EXECUTABLE_OUTPUT_PATH}/http_test)

# link to lib
target_link_libraries(http_test http common)
