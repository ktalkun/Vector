cmake_minimum_required(VERSION 3.13)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME_LIBRARY VectorLibrary CACHE INTERNAL "")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

enable_language(CXX)

add_library(${PROJECT_NAME_LIBRARY} SHARED vector.cpp vector.h)