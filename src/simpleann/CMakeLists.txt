CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(simpleann)

SET( sources 
  simpleann.c
  transfer.c
)

ADD_LIBRARY(simpleann ${sources})

SET_TARGET_PROPERTIES( simpleann  PROPERTIES
  VERSION 1.0.0
  SOVERSION 1 )

INSTALL( TARGETS simpleann DESTINATION lib )

