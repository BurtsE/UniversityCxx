#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <grades.hpp>
#include <string>
#include <vector>

enum class ProjectType { ERW, GP };

/**
 * @brief Project represents student's project.
 * 
 * Includes project's info and grades
 * 
 */
class Project {
private:
    std::string theme;
    std::string location;
    Grades grades;
    Project();
    void setup_grades(ProjectType type);
public:
    Project(ProjectType type);
    Project(std::string _theme, std::string _location, ProjectType type);

    Project(const Project&) = default;
    Project(Project&&) = default;
    Project& operator=(const Project&) = default;
    ~Project() = default;

    std::string get_theme() { return this->theme; };
    std::string get_location() { return this->location; };
    Grades get_grades() { return this->grades; };

    /**
     * @brief Set the theme of the project
     * 
     * @param _theme 
     */
    void set_theme(std::string _theme) { this->theme = _theme; }

    /**
     * @brief Set the location of the project
     * 
     * @param _location 
     */
    void set_location(std::string _location) { this->location = _location; }

    /**
     * @brief Set the grade by the member of the committee
     * 
     * @param member 
     * @param grade 
     */
    void set_grade(int member, int grade) { this->grades.set_grade(member, grade); };
};

#endif