#ifndef GRADES_HPP
#define GRADES_HPP
#include <vector>
#include <stdexcept>

class Grades {
private:
    std::vector<unsigned> grades;
    
public:
    Grades(): grades(0){};
    Grades(size_t  subjects_number): grades(subjects_number){};
    Grades(const Grades&) = default;
    Grades(Grades&&) = default;
    Grades& operator=(const Grades&) = default;
    ~Grades() = default;

    void set_grade(long unsigned int subject, unsigned result);

    std::vector<unsigned> get_values() { return grades; }
};

#endif