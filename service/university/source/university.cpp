#include "university.hpp"

#include <future>
#include <functional>



ITable::student_code University::admission(std::string _name, GroupIndex _groupIndex, Department _departmentNumber) {

    auto student = StudentBuilder::create_student( _name, 
         _groupIndex,  _departmentNumber, StudentCategory::JUNIOR);

    storage_.add_student(next_code, student);
    return next_code++;
}

void University::promote_student(ITable::student_code code) {

    auto student = storage_.get_student(code);
    if (student.get() == nullptr) {
        throw std::invalid_argument("student does not exists");
    }

    auto category = student.get()->get_category();

    if (category == StudentCategory::GRADUATE) {
        throw std::logic_error("student already graduated");
    }

 

    auto new_student = StudentBuilder::create_student(student.get()->get_name(), 
        student.get()->get_group_index(), student.get()->get_department_number(), ++category);


    storage_.add_student(code, new_student);
}

void University::expel_student(ITable::student_code code){

    auto expelled = storage_.remove_student(code);

    if (!expelled) {
        throw std::logic_error("could not expel student");
    }
}

std::vector<std::pair<GroupIndex, double>> University::get_group_grades(Department _departmentNumber) {

    std::vector<std::future<std::pair<GroupIndex, double>>> mean_grades;

    for (auto idx = GroupIndex::A; idx != GroupIndex::LAST; idx++ ) {
        mean_grades.emplace_back(std::async(std::launch::async,
            std::bind(&University::get_grades_for_group, this, _departmentNumber, idx)));
    }

    std::vector<std::pair<GroupIndex, double>> grades;

    for (auto& f: mean_grades) {

        auto grade = f.get();

        grades.push_back(grade);

    }

    return grades;

}

std::pair<GroupIndex, double> University::get_grades_for_group(Department _departmentNumber, GroupIndex _groupIndex) {

    double total = 0;

    unsigned counter = 0;

    std::vector<unsigned> grades;

    Junior* junior;

    Senior* senior;

    for (auto it = storage_.begin(); it != storage_.end(); ++it) {

        auto s = (*it).second.get();

        if (s->get_department_number() != _departmentNumber)
            continue;

        if (s->get_group_index() != _groupIndex)
            continue;

        switch (s->get_category()) {

        case StudentCategory::GRADUATE: continue;

        case StudentCategory::JUNIOR:

            junior = static_cast<Junior*>(s);

            grades = junior->get_session_grades().get_values();

            for (auto grade : grades) {

                if (grade != 0) {

                    total += grade;

                    counter++;
                }
                
            }

            break;
        case StudentCategory::SENIOR:

            senior = static_cast<Senior*>(s);

            grades = senior->get_session_grades().get_values();

            for (auto grade : grades) {

                if (grade != 0) {

                    total += grade;

                    counter++;
                }

            }
            break;
        default:
            throw std::logic_error("undefined student in table");
        }
    }

    auto mean_grade = total;
    if (counter > 0) {
        mean_grade /= counter;
    }

    return std::pair<GroupIndex, double>(_groupIndex, mean_grade);
}


void University::set_student_session_grade(ITable::student_code code, size_t subject, unsigned grade) {

    auto student = storage_.get_student(code);

    if (student == nullptr) {
        throw std::logic_error("invalid student code");
    }

    auto category = student->get_category();
    
    Junior* j;
    Senior* s;

    switch (category) {
    case StudentCategory::JUNIOR:
        j = static_cast<Junior*>(student.get());
        j->set_session_grade(subject, grade);
        break;
    case StudentCategory::SENIOR:
        s = static_cast<Senior*>(student.get());
        s->set_session_grade(subject, grade);
        break;
    default:
        throw std::logic_error("can not set session grade");
    }
}