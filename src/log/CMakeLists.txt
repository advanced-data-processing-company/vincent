file(GLOB LOG_SRC 
    "*[^test].cpp"
    "*[^test].h")

file(GLOB LOG_TEST_SRC
    "*test.cpp")

# add library
add_library(log ${LOG_SRC})

# add test executable
add_executable(log_test ${LOG_TEST_SRC})

# link to lib
target_link_libraries(log_test log gtest)
