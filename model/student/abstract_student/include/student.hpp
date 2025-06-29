#pragma once

#include <string>
#include <vector>
#include <iostream>


enum class GroupIndex { A, B, C, D, E, F, LAST};

enum class Department { PK, MT, LAST };

enum class StudentCategory { UNDEFINED, JUNIOR, SENIOR, GRADUATE};


class Student {
private:
    Student();
protected:
    std::string name;
    GroupIndex idx;
    Department departmentNumber;
public:
    Student(std::string _name, GroupIndex _groupIndex, Department _departmentNumber): name(_name), idx(_groupIndex), departmentNumber(_departmentNumber){};
    Student(const Student&) = default;
    Student(Student&&) = default;
    virtual ~Student() = default;

    std::string getName() { return this->name; }
    GroupIndex getGroupIndex() { return this->idx; }
    Department getDepartmentNumber() { return this->departmentNumber; }

    void setGroupIndex(GroupIndex index) {this->idx = index;}

    virtual StudentCategory getCategory();

    friend std::ostream& operator<<(std::ostream&, const Student&);
};


std::ostream& operator <<(std::ostream& s, const Department& d);

std::ostream& operator<<(std::ostream& s, const GroupIndex& idx);

GroupIndex& operator++(GroupIndex& idx);

GroupIndex operator++(GroupIndex& idx, int);

Department& operator++(Department& idx);

Department operator++(Department& idx, int);

StudentCategory& operator++(StudentCategory& c);
