cmake_minimum_required(VERSION 3.16)
project (application)

set(CMAKE_CXX_STANDARD 23)

add_library(application STATIC source/app.cpp)

target_include_directories(application PUBLIC include)

target_link_libraries(application PUBLIC cli_controller university)

add_executable(my_app ./source/main.cpp)

target_link_libraries(my_app PUBLIC application)
