cmake_minimum_required(VERSION 3.16)
project(project)

set(CMAKE_CXX_STANDARD 23)

add_library(project STATIC source/project.cpp)

target_include_directories(project PUBLIC include)

target_link_libraries(project PUBLIC grades)