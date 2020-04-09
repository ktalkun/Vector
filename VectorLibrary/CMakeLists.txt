cmake_minimum_required(VERSION 3.13)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME VectorLibrary)

add_library(${PROJECT_NAME} SHARED vector.cpp vector.h)