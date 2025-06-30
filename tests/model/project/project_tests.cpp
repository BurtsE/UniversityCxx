#include <project.hpp>
#include <catch2/catch.hpp>

TEST_CASE("PROJECT") {
    SECTION("CONSTRUCTOR") {
        auto theme = "theme";
        auto location = "location";
        auto project_type = ProjectType::ERW;
        Project p = Project(theme, location, project_type);
        REQUIRE(p.get_theme() == theme);
        REQUIRE(p.get_location() == location);
    }
    SECTION("TYPE") {
        REQUIRE(Project(ProjectType::ERW).get_grades().get_values().size() == 4);
        REQUIRE(Project(ProjectType::GP).get_grades().get_values().size() == 5);
    }
    SECTION("SETTERS") {
        auto theme = "theme";
        auto location = "location";
        auto project_type = ProjectType::ERW;
        Project p = Project(project_type);
        p.set_location(location);
        p.set_theme(theme);
        REQUIRE(p.get_theme() == theme);
        REQUIRE(p.get_location() == location);
    }
}
