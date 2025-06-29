#include <junior.hpp>
#include <senior.hpp>
#include <graduate.hpp>
#include <catch2/catch.hpp>

TEST_CASE("STUDENT") {
    auto name = "name";
    auto group_index = GroupIndex::A;
    auto department_number = Department::PK;
    Student s = Student(name, group_index, department_number);
    SECTION("CONSTRUCTOR") {
        REQUIRE( s.getName() == name );
        REQUIRE( s.getCategory() == StudentCategory::UNDEFINED );
        REQUIRE( s.getGroupIndex() == group_index );
        REQUIRE( s.getDepartmentNumber() == department_number );
    }
    SECTION("SETTER") {   
        auto group_index2 = GroupIndex::B;
        s.setGroupIndex(group_index2);
        REQUIRE( s.getGroupIndex() == group_index2 );
    }
}

TEST_CASE("JUNIOR") {
    auto name = "name";
    auto group_index = GroupIndex::A;
    auto department_number = Department::PK;
    Junior j = Junior(name, group_index, department_number);
    SECTION("CONSTRUCTOR") {
        REQUIRE( j.getName() == name );
        REQUIRE( j.getCategory() == StudentCategory::JUNIOR );
        REQUIRE( j.getGroupIndex() == group_index );
        REQUIRE( j.getDepartmentNumber() == department_number );
        REQUIRE( j.get_session_grades().get_values().size() == 5 );
    }
    SECTION("SETTER") {
        auto subject = 0;
        auto grade = 4;
        j.setSessionGrade(subject, grade);
        REQUIRE( j.get_session_grades().get_values().at(subject) == grade );
    }
}