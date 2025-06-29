cmake_minimum_required(VERSION 3.16)
project(grades)

set(CMAKE_CXX_STANDARD 23)

add_library(grades STATIC source/grades.cpp)

target_include_directories(grades PUBLIC include)