cmake_minimum_required(VERSION 2.8)
project(simpleann)

include_directories( "${PROJECT_SOURCE_DIR}/src" )

add_subdirectory(tests)

SET( sources 
  src/simpleann.c
)


add_library(simpleann ${sources})

