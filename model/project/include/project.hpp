#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <grades.hpp>
#include <string>
#include <vector>

enum class ProjectType { ERW, GP };
class Project {
private:
    std::string theme;
    std::string location;
    Grades grades;
    Project();
    void setupGrades(ProjectType type);
public:
    Project(ProjectType type);
    Project(std::string _theme, std::string _location, ProjectType type);

    Project(const Project&) = default;
    Project(Project&&) = default;
    Project& operator=(const Project&) = default;
    ~Project() = default;

    std::string getTheme() { return this->theme; };
    std::string getLocation() { return this->location; };
    Grades getGrades() { return this->grades; };

    void setTheme(std::string _theme) { this->theme = _theme; }
    void setLocation(std::string _location) { this->location = _location; }

    void setGrade(int subject, int result) { this->grades.set_grade(subject, result); };
};

#endif