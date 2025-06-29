cmake_minimum_required(VERSION 3.16)
project(junior)

set(CMAKE_CXX_STANDARD 23)

add_library(junior STATIC source/junior.cpp)

target_include_directories(junior PUBLIC include)

target_link_libraries(junior PUBLIC student grades)
