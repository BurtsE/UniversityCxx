#pragma once

#include <string>
#include <vector>
#include <stdexcept>

#include "student.hpp"
#include "grades.hpp"
#include "project.hpp"

/**
 * @brief Senior student.
 * 
 * Has grades for last session and project.
 * 
 * Amount of subjects for session set to 4 by default.
 * 
 * Project type set to ERW by default
 * 
 */
class Senior: public Student {
private:
    Grades sessionGrades;
    Project erw;

public:
    /**
     * @brief Construct a new Senior object
     * 
     * @param _name 
     * @param _groupIndex 
     * @param _departmentNumber 
     */
    Senior(std::string _name, GroupIndex _groupIndex, Department _departmentNumber): 
        Student(_name, _groupIndex, _departmentNumber), 
        sessionGrades(Grades(4)),
        erw(Project(ProjectType::ERW)) {};
    Senior(const Senior&) = default;
    Senior(Senior&&) = default;
    ~Senior() override = default;

    /**
     * @brief Get the session grades object
     * 
     * @return Grades 
     */
    Grades get_session_grades() { return this->sessionGrades; }

    /**
     * @brief Get the project object
     * 
     * @return Project 
     */
    Project get_project() { return this->erw; }
    /**
     * @brief Set the session grade object
     * 
     * @param subject 
     * @param result 
     * @return Senior& 
     */
    Senior& set_session_grade(int subject, int result);

    /**
     * @brief Set the projectgrade object
     * 
     * @param subject 
     * @param result 
     * @return Senior& 
     */
    Senior& set_projectgrade(int subject, int result);

    /**
     * @brief Set the project object
     * 
     * @param _theme 
     * @param _location 
     * @return Senior& 
     */
    Senior& set_project(std::string _theme, std::string _location);

    /**
     * @brief Get the category of the student
     * 
     * @return StudentCategory 
     */
    StudentCategory get_category() override;

};

