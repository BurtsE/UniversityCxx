cmake_minimum_required(VERSION 3.16)
project (repository)

set(CMAKE_CXX_STANDARD 23)

add_library(repository INTERFACE)
target_link_libraries(repository INTERFACE student)
target_include_directories(repository INTERFACE include)