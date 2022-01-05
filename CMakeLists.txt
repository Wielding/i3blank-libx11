cmake_minimum_required(VERSION 3.21)
project(i3blank_libx11 C)

find_package(X11 REQUIRED)

set(CMAKE_C_STANDARD 99)

add_executable(i3blank_libx11 main.c)
target_link_libraries(i3blank_libx11 ${X11_LIBRARIES})


