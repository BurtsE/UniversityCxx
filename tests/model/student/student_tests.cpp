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
        REQUIRE( s.get_name() == name );
        REQUIRE( s.get_category() == StudentCategory::UNDEFINED );
        REQUIRE( s.get_group_index() == group_index );
        REQUIRE( s.get_department_number() == department_number );
    }
    SECTION("SETTER") {   
        auto group_index2 = GroupIndex::B;
        s.set_group_index(group_index2);
        REQUIRE( s.get_group_index() == group_index2 );
    }
}

TEST_CASE("JUNIOR") {
    auto name = "name";
    auto group_index = GroupIndex::A;
    auto department_number = Department::PK;
    Junior j = Junior(name, group_index, department_number);
    SECTION("CONSTRUCTOR") {
        REQUIRE( j.get_name() == name );
        REQUIRE( j.get_category() == StudentCategory::JUNIOR );
        REQUIRE( j.get_group_index() == group_index );
        REQUIRE( j.get_department_number() == department_number );
        REQUIRE( j.get_session_grades().get_values().size() == 5 );
    }
    SECTION("SETTER") {
        auto subject = 0;
        unsigned grade = 4;
        j.set_session_grade(subject, grade);
        REQUIRE( j.get_session_grades().get_values().at(subject) == grade );
    }
}