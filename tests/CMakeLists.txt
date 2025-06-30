cmake_minimum_required(VERSION 3.16)
project (tests)

find_package(Catch2 2 REQUIRED)

add_executable(tests 
    ./model/grades/grades_tests.cpp
    ./model/builder/builder_tests.cpp
    ./model/project/project_tests.cpp
    ./model/student/student_tests.cpp
    ./repository/in_memory_repository_tests.cpp
)

target_include_directories(tests PUBLIC include)

target_link_libraries(tests PUBLIC junior senior graduate grades builder in_memory_repository Catch2::Catch2)

