file(GLOB CONFIG_SRC 
    "*[^test].cpp"
    "*[^test].h")

file(GLOB CONFIG_TEST_SRC
    "*test.cpp")

# add library
add_library(config ${CONFIG_SRC})
target_link_libraries(config common)

# add test executable
add_executable(config_test ${CONFIG_TEST_SRC})

add_test(config ${EXECUTABLE_OUTPUT_PATH}/config_test)

# link to lib
target_link_libraries(config_test config)
