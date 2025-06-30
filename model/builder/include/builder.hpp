#ifndef BUILDER_HPP
#define BUILDER_HPP

#include "junior.hpp"
#include "senior.hpp"
#include "graduate.hpp"
#include <memory>

class StudentBuilder {
public:
    static std::shared_ptr<Student> create_student(std::string _name, GroupIndex _groupIndex, Department _departmentNumber, StudentCategory category);
    StudentBuilder() = delete;
};

#endif