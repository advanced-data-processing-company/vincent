file(GLOB LIB_SRC
    "*.cpp"
    "*.h"
    "*.c"
)

#file(GLOB TEST_SRC
   # "*test.cpp")

#list(REMOVE_ITEM LIB_SRC ${LIB_SRC})

# add library
add_library(http_parser ${LIB_SRC})

# add test executable
#add_executable(http_parser_test ${TEST_SRC})

#add_test(http ${EXECUTABLE_OUTPUT_PATH}/http_test)

# link to lib
#target_link_libraries(http_test http common)
