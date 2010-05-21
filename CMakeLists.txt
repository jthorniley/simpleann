CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(simpleann)

OPTION( BUILD_SHARED_LIBS "Compile as shared library (rather than static)?" ON )

INCLUDE_DIRECTORIES( "${PROJECT_SOURCE_DIR}/src" )

ADD_SUBDIRECTORY(src/simpleann)
ADD_SUBDIRECTORY(examples)

