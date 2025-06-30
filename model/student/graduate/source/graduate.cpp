#include "graduate.hpp"


Graduate& Graduate::set_project(std::string theme, std::string location) {
    gp.setTheme(theme);
    gp.setLocation(location);
    return *this;
};

Graduate& Graduate::set_project_grade(int subject, int result) {
    this->gp.setGrade(subject, result);
    return *this;
}

StudentCategory Graduate::get_category(){
    return StudentCategory::GRADUATE;
}