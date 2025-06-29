cmake_minimum_required(VERSION 3.16)
project (hw5)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_subdirectory(model)
add_subdirectory(repository)
add_subdirectory(service)
add_subdirectory(controller)
add_subdirectory(application)



