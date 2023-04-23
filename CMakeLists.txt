cmake_minimum_required(VERSION 3.24)
project(project C)

set(CMAKE_C_STANDARD 23)

add_executable(project main.c learncplus.cpp learncplus.h)

add_library(str string/string_.h string/string_.c Tasks/string_.c Tasks/string_.h)

target_link_libraries(project str)
