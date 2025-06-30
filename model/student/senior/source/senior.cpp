#include "senior.hpp"

Senior& Senior::setSessionGrade(int subject, int result) {
    this->sessionGrades.set_grade(subject, result);
    return *this;
}

Senior& Senior::setProject(std::string theme, std::string location) {
    erw.setTheme(theme);
    erw.setLocation(location);
    return *this;
};

Senior& Senior::setProjectGrade(int subject, int result) {
    this->erw.setGrade(subject, result);
    return *this;
}

StudentCategory Senior::getCategory(){
    return StudentCategory::SENIOR;
}