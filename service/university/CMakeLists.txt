cmake_minimum_required( VERSION 3.16 )
project( university )

set( CMAKE_CXX_STANDARD 23)

add_library(university STATIC source/university.cpp)

target_include_directories(university PUBLIC include)

target_link_libraries(university PUBLIC in_memory_repository builder)

