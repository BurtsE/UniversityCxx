#include "builder.hpp"

std::shared_ptr<Student> StudentBuilder::create_student(std::string name, GroupIndex groupIndex, Department departmentNumber, StudentCategory category) {

    auto group_index = static_cast<int> (groupIndex);
    if (0 > group_index  ||  group_index > 5 ) {
        throw std::logic_error("undefined group");
    }

    auto department_number = static_cast<int> (departmentNumber);

    if (0 > department_number  ||  department_number > 1 ) {
        throw std::logic_error("undefined department");
    }

    switch (category) {
        case StudentCategory::JUNIOR:
            return std::make_shared<Junior>(Junior(name, groupIndex, departmentNumber));
        case StudentCategory::SENIOR:
            return std::make_shared<Senior>(Senior(name, groupIndex, departmentNumber));
        case StudentCategory::GRADUATE:
            return std::make_shared<Graduate>(Graduate(name, groupIndex, departmentNumber));
        default:
            throw std::logic_error("undefined category");
    }
};
