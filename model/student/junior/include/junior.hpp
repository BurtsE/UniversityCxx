#pragma once

#include <string>
#include <vector>
#include <stdexcept>

#include <student.hpp>
#include <grades.hpp>

/**
 * @brief Junior student.
 * 
 * Only has grades for last session.
 * 
 * Amount of subjects for session set to 5 by default
 * 
 */
class Junior: public Student {
    Grades sessionGrades;
public:
    /**
     * @brief Construct a new Junior object
     * 
     * @param _name 
     * @param _groupIndex 
     * @param _departmentNumber 
     */
    Junior(std::string _name, GroupIndex _groupIndex, Department _departmentNumber): Student(_name, _groupIndex, _departmentNumber), sessionGrades(Grades(5)) {}
    Junior(const Junior&) = default;
    Junior(Junior&&) = default;
    ~Junior() override = default;

    /**
     * @brief Set the session grade object
     * 
     * @param subject 
     * @param result 
     */
    void set_session_grade(int subject, int result);
    /**
     * @brief Get the category of the student
     * 
     * @return StudentCategory 
     */
    StudentCategory get_category() override;

    /**
     * @brief Get the session grades object
     * 
     * @return Grades 
     */
    Grades get_session_grades() { return sessionGrades; };
};

