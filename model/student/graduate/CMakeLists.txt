cmake_minimum_required(VERSION 3.16)
project(graduate)

set(CMAKE_CXX_STANDARD 23)

add_library(graduate STATIC source/graduate.cpp)

target_include_directories(graduate PUBLIC include)

target_link_libraries(graduate PUBLIC student project)
