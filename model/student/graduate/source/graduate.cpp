#include "graduate.hpp"


Graduate& Graduate::setProject(std::string theme, std::string location) {
    gp.setTheme(theme);
    gp.setLocation(location);
    return *this;
};

Graduate& Graduate::setProjectGrade(int subject, int result) {
    this->gp.setGrade(subject, result);
    return *this;
}

StudentCategory Graduate::getCategory(){
    return StudentCategory::GRADUATE;
}