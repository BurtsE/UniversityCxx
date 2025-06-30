#pragma once

#include <string>
#include <vector>
#include <iostream>


enum class GroupIndex { A, B, C, D, E, F, LAST};

enum class Department { PK, MT, LAST };

enum class StudentCategory { UNDEFINED, JUNIOR, SENIOR, GRADUATE};

/**
 * @brief 
 * 
 */
class Student {
private:
    Student();
protected:
    std::string name;
    GroupIndex idx;
    Department departmentNumber;
public:
    /**
     * @brief Construct a new Student object
     * 
     * @param _name students name
     * @param _groupIndex index of student's group
     * @param _departmentNumber index of student's department
     */
    Student(std::string _name, GroupIndex _groupIndex, Department _departmentNumber): name(_name), idx(_groupIndex), departmentNumber(_departmentNumber){};
    Student(const Student&) = default;
    Student(Student&&) = default;
    virtual ~Student() = default;

    /**
     * @brief Get the name object
     * 
     * @return std::string 
     */
    std::string get_name() { return this->name; }

    /**
     * @brief Get the group index object
     * 
     * @return GroupIndex 
     */
    GroupIndex get_group_index() { return this->idx; }

    /**
     * @brief Get the department number object
     * 
     * @return Department 
     */
    Department get_department_number() { return this->departmentNumber; }

    /**
     * @brief Set the group index object
     * 
     * @param index 
     */
    void set_group_index(GroupIndex index) {this->idx = index;}

    /**
     * @brief Get the category object
     * 
     * @return StudentCategory 
     */
    virtual StudentCategory get_category();

    friend std::ostream& operator<<(std::ostream&, const Student&);
};


std::ostream& operator <<(std::ostream& s, const Department& d);

std::ostream& operator<<(std::ostream& s, const GroupIndex& idx);

GroupIndex& operator++(GroupIndex& idx);

GroupIndex operator++(GroupIndex& idx, int);

Department& operator++(Department& idx);

Department operator++(Department& idx, int);

StudentCategory& operator++(StudentCategory& c);
