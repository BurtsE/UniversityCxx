#pragma once

#include <in_memory_repository.hpp>
#include <builder.hpp>


/**
 * @brief Service class for the app
 * 
 * Handles work with storage, generates student's codes
 * 
 */
class University { 

private:

    InMemoryTable& storage_;

    ITable::student_code next_code = 0;

    std::pair<GroupIndex, double> get_grades_for_group(Department _departmentNumber, GroupIndex _groupIndex);

public:
    University(InMemoryTable& storage): storage_(storage){};

    /**
     * @brief Creates Junior student in the database
     * 
     * @param _name 
     * @param _groupIndex 
     * @param _departmentNumber 
     * @return ITable::student_code UUID of a student
     */
    ITable::student_code admission(std::string _name, GroupIndex _groupIndex, Department _departmentNumber);

    /**
     * @brief creates another student with promoted class
     * 
     * throws error if student could not be graduated
     * 
     * @param code 
     */
    void promote_student(ITable::student_code code);

    /**
     * @brief deletes student from database
     * 
     * @param code 
     */
    void expel_student(ITable::student_code code);
    
    /**
     * @brief Get the group grades
     * 
     * Runs in multiple threads (one for each student group type) 
     * 
     * @param _departmentNumber 
     * @return std::vector<std::pair<GroupIndex, double>> 
     */
    std::vector<std::pair<GroupIndex, double>> get_group_grades(Department _departmentNumber);

    /**
     * @brief Set the student session grade for subject
     * 
     * @param code 
     * @param subject 
     * @param grade 
     */
    void set_student_session_grade(ITable::student_code code, size_t subject, unsigned grade);

};