#include "grades.hpp"

void Grades::setGrade(long unsigned int subject, unsigned result) {
    if (subject >= this->grades.capacity()) {
        throw std::invalid_argument("invalid subject");
    }
    grades[subject] = result;
}