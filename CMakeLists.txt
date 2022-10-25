cmake_minimum_required(VERSION 3.23)
project(DTG C)

set(CMAKE_C_STANDARD 99)
add_executable(library library.c)

add_library(DTG library.c)
