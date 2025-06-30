#include <catch2/catch.hpp>
#include <builder.hpp>

TEST_CASE("BUILDER") {
    SECTION("BASE") {
        auto name = "Student";
        auto s = StudentBuilder::create_student(name, static_cast<GroupIndex>(0), static_cast<Department>(0), StudentCategory::JUNIOR);
        REQUIRE( s->get_name() == name );
        REQUIRE( s->get_department_number() == Department::PK );
        REQUIRE( s->get_group_index() == GroupIndex::A );
        REQUIRE( s->get_category() == StudentCategory::JUNIOR );
    }
    SECTION("JUNIOR") {
        auto s = StudentBuilder::create_student("", static_cast<GroupIndex>(0), static_cast<Department>(0), StudentCategory::JUNIOR);
        REQUIRE( s->get_category() == StudentCategory::JUNIOR );
        REQUIRE_NOTHROW( dynamic_cast<Junior*>(s.get()) != nullptr );
    }
    SECTION("SENIOR") {
        auto s = StudentBuilder::create_student("", static_cast<GroupIndex>(0), static_cast<Department>(0), StudentCategory::SENIOR);
        REQUIRE( s->get_category() == StudentCategory::SENIOR );
        REQUIRE_NOTHROW( dynamic_cast<Senior*>(s.get()) != nullptr );
    }
    SECTION("GRADUATE") {
        auto s = StudentBuilder::create_student("", static_cast<GroupIndex>(0), static_cast<Department>(0), StudentCategory::GRADUATE);
        REQUIRE( s->get_category() == StudentCategory::GRADUATE );
        REQUIRE_NOTHROW( dynamic_cast<Graduate*>(s.get()) != nullptr );
    }
}