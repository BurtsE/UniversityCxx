#ifndef GRADES_HPP
#define GRADES_HPP
#include <vector>
#include <stdexcept>


/**
 * @brief Object representing grades
 * 
 */
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
    /**
     * @brief Set the grade for specific subject
     * 
     * @param subject 
     * @param result 
     */
    void set_grade(long unsigned int subject, unsigned result);

    /**
     * @brief Get the values object
     * 
     * @return std::vector<unsigned> 
     */
    std::vector<unsigned> get_values() { return grades; }
};

#endif