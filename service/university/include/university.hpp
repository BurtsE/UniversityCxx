#pragma once

#include <in_memory_repository.hpp>
#include <builder.hpp>

class University {

private:

    InMemoryTable& storage_;

    ITable::student_code next_code = 0;

    std::pair<GroupIndex, double> get_grades_for_group(Department _departmentNumber, GroupIndex _groupIndex);

public:
    University(InMemoryTable& storage): storage_(storage){};

    ITable::student_code admission(std::string _name, GroupIndex _groupIndex, Department _departmentNumber);

    void promote_student(ITable::student_code code);

    void expel_student(ITable::student_code code);

    std::vector<std::pair<GroupIndex, double>> get_group_grades(Department _departmentNumber);

    void set_student_session_grade(ITable::student_code code, size_t subject, unsigned grade);

};