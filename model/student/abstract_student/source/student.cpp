#include "student.hpp"


std::ostream& operator <<(std::ostream& s, const Department& d) {
    switch (d) {
    case Department::PK:
        s << "PK";
        break;
    case Department::MT:
        s << "MT";
        break;
    case Department::LAST:
        s << "undefined department";
        break;
    }
    return s;
}

std::ostream& operator<<(std::ostream& s, const GroupIndex& idx){
    switch (idx) {
    case GroupIndex::A:
        s << "A";
        break;
    case GroupIndex::B:
        s << "B";
        break;
    case GroupIndex::C:
        s << "C";
        break;
    case GroupIndex::D:
        s << "D";
        break;
    case GroupIndex::E:
        s << "E";
        break;
    case GroupIndex::F:
        s << "F";
        break;
    case GroupIndex::LAST:
        s << "undefined group";
        break;
    }
    return s;
}


std::ostream& operator<<(std::ostream& s, const Student& student){
    s << student.name << " " << student.departmentNumber << " " << student.idx;
    return s;
}

StudentCategory Student::getCategory() {
    return StudentCategory::UNDEFINED;
}


StudentCategory& operator++(StudentCategory& c) {
    if (c == StudentCategory::GRADUATE) {
        c = static_cast<StudentCategory>(0);
    } else {
        c = static_cast<StudentCategory>(static_cast<int>(c) + 1);
    }
    return c;
}

GroupIndex& operator++(GroupIndex& idx) {
    if (idx == GroupIndex::LAST) {
        idx = static_cast<GroupIndex>(0);
    } else {
        idx = static_cast<GroupIndex>(static_cast<int>(idx) + 1);
    }
    return idx;
}
GroupIndex operator++(GroupIndex& idx, int) {
    GroupIndex temp = idx;
    ++idx;
    return temp;
}

Department& operator++(Department& idx) {
    if (idx == Department::LAST) {
        idx = static_cast<Department>(0);
    } else {
        idx = static_cast<Department>(static_cast<int>(idx) + 1);
    }
    return idx;
}

Department operator++(Department& idx, int) {
    Department temp = idx;
    ++idx;
    return temp;
}