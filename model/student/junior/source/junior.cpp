#include "junior.hpp"


StudentCategory Junior::getCategory(){
    return StudentCategory::JUNIOR;
}
void Junior::setSessionGrade(int subject, int result) {
    this->sessionGrades.setGrade(subject, result);
}

