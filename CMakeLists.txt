cmake_minimum_required(VERSION 3.13)
project("${PROJECT_NAME}")

set(PROJECT_NAME Vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(VectorLibrary)
include_directories(VectorTest)

set(CMAKE_CXX_FLAGS "--coverage")

add_subdirectory(VectorLibrary)
add_subdirectory(VectorTest)