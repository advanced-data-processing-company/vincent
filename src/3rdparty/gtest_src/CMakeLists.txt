# TODO(thy): this is very urgly, optimise this

file(GLOB GTEST_SRC
    "src/*[^all].cc")

# add library
add_library(gtest ${GTEST_SRC})

target_include_directories(gtest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
