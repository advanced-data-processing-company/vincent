project(app)

file(GLOB src 
"*.cpp"
"*.h")

# add excutable
add_executable(app ${src})

target_link_libraries(app ${COMMON_LIB} protobuf proto)