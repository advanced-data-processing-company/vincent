get_filename_component(TARGET ${CMAKE_CURRENT_SOURCE_DIR} NAME)
file(GLOB src 
"*.cpp"
"*.h")

# add excutable
add_executable(${TARGET} ${src})

target_link_libraries(${TARGET} protobuf protoc)
