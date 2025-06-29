#include <catch2/catch.hpp>
#include <builder.hpp>

TEST_CASE("BUILDER") {
    SECTION("BASE") {
        auto name = "Student";
        auto s = StudentBuilder::CreateStudent(name, static_cast<GroupIndex>(0), static_cast<Department>(0), StudentCategory::JUNIOR);
        REQUIRE( s->getName() == name );
        REQUIRE( s->getDepartmentNumber() == Department::PK );
        REQUIRE( s->getGroupIndex() == GroupIndex::A );
        REQUIRE( s->getCategory() == StudentCategory::JUNIOR );
    }
    SECTION("JUNIOR") {
        auto s = StudentBuilder::CreateStudent("", static_cast<GroupIndex>(0), static_cast<Department>(0), StudentCategory::JUNIOR);
        REQUIRE( s->getCategory() == StudentCategory::JUNIOR );
        REQUIRE_NOTHROW( dynamic_cast<Junior*>(s.get()) != nullptr );
    }
    SECTION("SENIOR") {
        auto s = StudentBuilder::CreateStudent("", static_cast<GroupIndex>(0), static_cast<Department>(0), StudentCategory::SENIOR);
        REQUIRE( s->getCategory() == StudentCategory::SENIOR );
        REQUIRE_NOTHROW( dynamic_cast<Senior*>(s.get()) != nullptr );
    }
    SECTION("GRADUATE") {
        auto s = StudentBuilder::CreateStudent("", static_cast<GroupIndex>(0), static_cast<Department>(0), StudentCategory::GRADUATE);
        REQUIRE( s->getCategory() == StudentCategory::GRADUATE );
        REQUIRE_NOTHROW( dynamic_cast<Graduate*>(s.get()) != nullptr );
    }
}