cmake_minimum_required(VERSION 4.2.3)

project(client_networks C)

set(CMAKE_C_STANDARD 17)

add_executable(client_networks 
    "src/main.c"
    "src/testing.c"
    "src/matrix.c"
    "src/stringx.c"
    "src/client_socket.c"
)
target_include_directories(client_networks PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
