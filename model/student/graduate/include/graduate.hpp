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

    Project getProject() { return this->gp; }

    Graduate& setProjectGrade(int subject, int result);
    Graduate& setProject(std::string _theme, std::string _location);

    StudentCategory getCategory() override;

};

