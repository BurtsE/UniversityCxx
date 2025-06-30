#include "senior.hpp"

Senior& Senior::set_session_grade(int subject, int result) {
    this->sessionGrades.set_grade(subject, result);
    return *this;
}

Senior& Senior::set_project(std::string theme, std::string location) {
    erw.set_theme(theme);
    erw.set_location(location);
    return *this;
};

Senior& Senior::set_projectgrade(int subject, int result) {
    this->erw.set_grade(subject, result);
    return *this;
}

StudentCategory Senior::get_category(){
    return StudentCategory::SENIOR;
}