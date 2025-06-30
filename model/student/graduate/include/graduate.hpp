#pragma once


#include "student.hpp"
#include "project.hpp"

/**
 * @brief Graduated student.
 * 
 * Only has project data
 * 
 */
class Graduate: public Student {
private:
    Project gp;   
public:
    /**
     * @brief Construct a new Graduate student.
     * 
     * Progect type set to gp by default
     * 
     * @param _name 
     * @param _groupIndex 
     * @param _departmentNumber 
     */
    Graduate(std::string _name, GroupIndex _groupIndex, Department _departmentNumber): Student(_name, _groupIndex, _departmentNumber), gp(Project(ProjectType::GP))  {}
    Graduate(const Graduate&) = default;
    Graduate(Graduate&&) = default;
    ~Graduate() override = default;

    /**
     * @brief Get the project object
     * 
     * @return Project 
     */
    Project get_project() { return this->gp; }

    /**
     * @brief Set the project grade object
     * 
     * @param subject 
     * @param result 
     * @return Graduate& 
     */
    Graduate& set_project_grade(int subject, int result);

    /**
     * @brief Set the project object
     * 
     * @param _theme 
     * @param _location 
     * @return Graduate& 
     */
    Graduate& set_project(std::string _theme, std::string _location);

    /**
     * @brief Get the category of student
     * 
     * @return StudentCategory 
     */
    StudentCategory get_category() override;

};

