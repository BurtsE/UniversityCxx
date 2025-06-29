cmake_minimum_required(VERSION 3.16)
project(senior)

set(CMAKE_CXX_STANDARD 23)

add_library(senior STATIC source/senior.cpp)

target_include_directories(senior PUBLIC include)

target_link_libraries(senior PUBLIC student grades project)

