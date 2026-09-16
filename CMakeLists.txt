cmake_minimum_required(VERSION 4.3.0)

project(client_networks C)

set(CMAKE_C_STANDARD 17)

add_executable(client_networks 
    "src/main.c"
    "src/testing.c"
)
target_include_directories(client_networks PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
