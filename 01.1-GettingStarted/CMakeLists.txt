cmake_minimum_required(VERSION 3.12)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(hello hello.c)
add_executable(temperature temperature.c)
add_executable(countchar countchar.c)
add_executable(countlines countlines.c)
add_executable(countwords countwords.c)