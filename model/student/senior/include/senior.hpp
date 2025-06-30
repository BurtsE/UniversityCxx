#pragma once

#include <string>
#include <vector>
#include <stdexcept>

#include "student.hpp"
#include "grades.hpp"
#include "project.hpp"
class Senior: public Student {
private:
    Grades sessionGrades;
    Project erw;

public:
    Senior(std::string _name, GroupIndex _groupIndex, Department _departmentNumber): 
        Student(_name, _groupIndex, _departmentNumber), 
        sessionGrades(Grades(4)),
        erw(Project(ProjectType::ERW)) {};
    Senior(const Senior&) = default;
    Senior(Senior&&) = default;
    ~Senior() override = default;

    Grades get_session_grades() { return this->sessionGrades; }
    Project get_project() { return this->erw; }
    
    Senior& set_session_grade(int subject, int result);
    Senior& set_projectgrade(int subject, int result);
    Senior& set_project(std::string _theme, std::string _location);

    StudentCategory get_category() override;

};

