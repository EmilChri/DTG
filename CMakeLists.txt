cmake_minimum_required(VERSION 3.23)
project(DTG C)

set(CMAKE_C_STANDARD 99)
add_executable(library library.c)
add_executable(Workshop3_fun Workshop3_fun.c)
add_executable(Workshop3 Workshop3.c)

add_library(DTG library.c Workshop3.c Workshop3_fun.c)
