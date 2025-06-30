#pragma once

#include <student.hpp>
#include <string>
#include <memory>


class ITable {
public:

    using student_code = size_t;
 
    virtual ~ITable() = default;

    virtual void add_student(student_code key, std::shared_ptr<Student> student) = 0;

    virtual std::shared_ptr<Student> get_student(student_code code) = 0;

    virtual bool remove_student(student_code code) = 0;

    virtual std::vector<std::shared_ptr<Student>> get_all_students() = 0;

    virtual std::shared_ptr<Student> operator[] (student_code code) = 0;

};
