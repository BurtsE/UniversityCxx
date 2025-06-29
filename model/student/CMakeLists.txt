cmake_minimum_required(VERSION 3.16)
project(student)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(abstract_student)
add_subdirectory(junior)
add_subdirectory(senior)
add_subdirectory(graduate)