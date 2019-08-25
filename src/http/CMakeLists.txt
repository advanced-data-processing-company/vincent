file(GLOB LIB_SRC
    "*.cpp"
    "*.h")

file(GLOB HTTP_SRC
    "*.cpp"
    "*.h")

message(${HTTP_SRC})
add_executable(http ${HTTP_SRC})
link_directories(/usr/local/lib)
target_link_libraries(http
    curl
    )
