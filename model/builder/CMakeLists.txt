cmake_minimum_required(VERSION 3.16)
project(builder)

set(CMAKE_CXX_STANDARD 23)

add_library(builder STATIC source/builder.cpp)

target_include_directories(builder PUBLIC include)

target_link_libraries(builder PUBLIC junior senior graduate)

