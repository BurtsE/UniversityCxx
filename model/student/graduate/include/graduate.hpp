#pragma once


#include "student.hpp"
#include "project.hpp"


class Graduate: public Student {
private:
    Project gp;   
public:
    Graduate(std::string _name, GroupIndex _groupIndex, Department _departmentNumber): Student(_name, _groupIndex, _departmentNumber), gp(Project(ProjectType::GP))  {}
    Graduate(const Graduate&) = default;
    Graduate(Graduate&&) = default;
    ~Graduate() override = default;

    Project get_project() { return this->gp; }

    Graduate& set_project_grade(int subject, int result);
    Graduate& set_project(std::string _theme, std::string _location);

    StudentCategory get_category() override;

};

