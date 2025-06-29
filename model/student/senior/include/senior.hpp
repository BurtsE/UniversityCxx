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

    Grades getSessionGrades() { return this->sessionGrades; }
    Project getProject() { return this->erw; }
    
    Senior& setSessionGrade(int subject, int result);
    Senior& setProjectGrade(int subject, int result);
    Senior& setProject(std::string _theme, std::string _location);

    StudentCategory getCategory() override;

    Grades get_session_grades() { return sessionGrades; };
};

