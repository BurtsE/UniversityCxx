#include "project.hpp"

Project::Project(ProjectType type) {
    setup_grades(type);
};
Project::Project(std::string _theme, std::string _location, ProjectType _type): theme(_theme), location(_location){
    setup_grades(_type);
};

void Project::setup_grades(ProjectType type) {
    switch (type) {
        case ProjectType::ERW:
            this->grades = Grades(4);
            break;
        case ProjectType::GP:
            this->grades = Grades(5);
            break;
    }
}