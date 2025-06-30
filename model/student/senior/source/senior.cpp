#include "senior.hpp"

Senior& Senior::set_session_grade(int subject, int result) {
    this->sessionGrades.set_grade(subject, result);
    return *this;
}

Senior& Senior::set_project(std::string theme, std::string location) {
    erw.setTheme(theme);
    erw.setLocation(location);
    return *this;
};

Senior& Senior::set_projectgrade(int subject, int result) {
    this->erw.setGrade(subject, result);
    return *this;
}

StudentCategory Senior::get_category(){
    return StudentCategory::SENIOR;
}