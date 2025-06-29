#pragma once

#include <string>
#include <vector>
#include <stdexcept>

#include <student.hpp>
#include <grades.hpp>


class Junior: public Student {
    Grades sessionGrades;
public:
    Junior(std::string _name, GroupIndex _groupIndex, Department _departmentNumber): Student(_name, _groupIndex, _departmentNumber), sessionGrades(Grades(5)) {}
    Junior(const Junior&) = default;
    Junior(Junior&&) = default;
    ~Junior() override = default;

    void setSessionGrade(int subject, int result);
    StudentCategory getCategory() override;
    Grades get_session_grades() { return sessionGrades; };
};

