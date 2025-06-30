#define CATCH_CONFIG_MAIN

#include <grades.hpp>
#include <catch2/catch.hpp>

TEST_CASE("GRADES") {
    SECTION("CONSTRUCTOR") {
        for (size_t i = 0; i < 5; ++i) {
            REQUIRE( Grades(i).get_values().size() == i );
        }
    }
    SECTION("SETTER") {
        auto g = Grades(5);

        for (unsigned i = 0; i < 5; ++i) {
            g.set_grade(i , i);
            REQUIRE( g.get_values().at(i) == i );
        }
    }
    SECTION("THROW") {
        unsigned subject = 5;
        auto g = Grades(subject);
        REQUIRE_THROWS( g.set_grade(subject, 1) );
    }
}
