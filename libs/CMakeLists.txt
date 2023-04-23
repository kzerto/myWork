cmake_minimum_required(VERSION 3.24)
project(project C)

set(CMAKE_C_STANDARD 23)

add_executable(data_structures/vector/vector.c data_structures/vector/vector.h data_structures/vector/vector.h data_structures/vector/vector.c data_structures/vector/vector.c data_structures/vector/vector.c data_structures/vector/vector.c data_structures/vector/vector.c data_structures/vector/vector.c)

add_library( vector/vector.c data_structures/vector/vector.c)

target_link_libraries(project str)

