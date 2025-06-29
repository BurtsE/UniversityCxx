cmake_minimum_required(VERSION 3.16)
project (model)

find_package(Catch2 2 REQUIRED)

add_executable(tests 
    ./grades/grades_tests.cpp
    ./builder/builder_tests.cpp
    ./project/project_tests.cpp
)

target_include_directories(tests PUBLIC include)

target_link_libraries(tests PUBLIC junior senior graduate grades builder Catch2::Catch2)