cmake_minimum_required(VERSION 3.16)
project(student)

set(CMAKE_CXX_STANDARD 23)

add_library(student STATIC source/student.cpp)

target_include_directories(student PUBLIC include)
