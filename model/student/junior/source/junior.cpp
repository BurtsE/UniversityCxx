#include "junior.hpp"


StudentCategory Junior::get_category(){
    return StudentCategory::JUNIOR;
}
void Junior::set_session_grade(int subject, int result) {
    this->sessionGrades.set_grade(subject, result);
}

