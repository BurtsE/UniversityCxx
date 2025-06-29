#pragma once

#include <student.hpp>
#include <string>
#include <memory>


class ITable {
public:

    using student_code = size_t;
 
    virtual ~ITable() = default;

    virtual void addStudent(student_code key, std::shared_ptr<Student> student) = 0;

    virtual std::shared_ptr<Student> getStudent(student_code code) = 0;

    virtual bool removeStudent(student_code code) = 0;

    virtual std::vector<std::shared_ptr<Student>> getAllStudents() = 0;

    virtual std::shared_ptr<Student> operator[] (student_code code) = 0;

};
