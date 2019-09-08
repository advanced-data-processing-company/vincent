file(GLOB LIB_SRC
    "*.cpp"
    "*.h")

file(GLOB TEST_SRC
   "*test.cpp")

list(REMOVE_ITEM LIB_SRC ${TEST_SRC})

#file(GLOB Dir1_Sources ${CMAKE_CURRENT_SOURCE_DIR}/../http_parser/*.cpp)


#message("----" ${CMAKE_CURRENT_SOURCE_DIR})
#message("----" ${Dir1_Sources})
#file(GLOB Dir2_Sources RELATIVE "Dir2" "*.cpp")

#list(REMOVE_ITEM ${LIB_SRC})

# add library
add_library(http ${LIB_SRC})

#target_link_libraries(http common http_parser)

message("----" ${LIB_SRC})
# add test executable
#add_executable(clientinterface_test ${TEST_SRC} ${LIB_SRC}  ${Dir1_Sources} )

#add_test(http ${EXECUTABLE_OUTPUT_PATH}/clientinterface_test)

# link to lib
#target_link_libraries(clientinterface_test clientinterface common)
