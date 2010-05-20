cmake_minimum_required(VERSION 2.8)
project(simpleann)

add_executable(basic basic.c)
target_link_libraries(basic simpleann m)
