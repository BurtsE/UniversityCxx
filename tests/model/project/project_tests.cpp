#include <project.hpp>
#include <catch2/catch.hpp>

TEST_CASE("PROJECT") {
    SECTION("CONSTRUCTOR") {
        auto theme = "theme";
        auto location = "location";
        auto project_type = ProjectType::ERW;
        Project p = Project(theme, location, project_type);
        REQUIRE(p.getTheme() == theme);
        REQUIRE(p.getLocation() == location);
    }
    SECTION("TYPE") {
        REQUIRE(Project(ProjectType::ERW).getGrades().get_values().size() == 4);
        REQUIRE(Project(ProjectType::GP).getGrades().get_values().size() == 5);
    }
    SECTION("SETTERS") {
        auto theme = "theme";
        auto location = "location";
        auto project_type = ProjectType::ERW;
        Project p = Project(project_type);
        p.setLocation(location);
        p.setTheme(theme);
        REQUIRE(p.getTheme() == theme);
        REQUIRE(p.getLocation() == location);
    }
}
