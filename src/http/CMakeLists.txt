file(GLOB LIB_SRC
    "*.cpp"
    "*.h")

file(GLOB HTTP_SRC
    "*.cpp"
    "*.h")

message(${HTTP_SRC})
add_executable(http ${HTTP_SRC})
