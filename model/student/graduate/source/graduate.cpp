#include "graduate.hpp"


Graduate& Graduate::set_project(std::string theme, std::string location) {
    gp.set_theme(theme);
    gp.set_location(location);
    return *this;
};

Graduate& Graduate::set_project_grade(int subject, int result) {
    this->gp.set_grade(subject, result);
    return *this;
}

StudentCategory Graduate::get_category(){
    return StudentCategory::GRADUATE;
}