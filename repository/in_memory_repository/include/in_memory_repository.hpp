#pragma once

#include <table.hpp>
#include <student.hpp>
#include <shared_mutex>
#include <mutex>

/**
 * @brief Hash table for storing information about students in memory
 * 
 * Thread safe, but stores pointers to objects, which should not be modified
 * 
 * Stores data as a vector of Cells.
 * 
 */
class InMemoryTable: public ITable {

private:  

    /**
     * @brief Class for storing data in table
     * 
     * Includes key, pointer to object and deleted mark
     * 
     */
    class Cell {
    private:

        ITable::student_code key;

        std::shared_ptr<Student> value;

        bool is_deleted;

    public:
        Cell() = default;

        Cell(ITable::student_code _key, std::shared_ptr<Student> _student): key(_key), 
            value(std::move(_student)), is_deleted(false){};

        std::shared_ptr<Student> student() {return value;}

        ITable::student_code get_key() { return key; }

        /**
         * @brief Method checks if cell was never filled
         * 
         * Needed for avoiding collision 
         * 
         * @return true 
         * @return false 
         */
        bool is_empty() { return value.get() == nullptr && !is_deleted; }

        /**
         * @brief Method points that cell was deleted, removing ptr
         * 
         */
        void remove() { value = nullptr; is_deleted = true; }
    };

    /**
     * @brief Class for iterating through table
     * 
     * Thread safe
     * 
     */
    class Iterator{

        using iterator_category = std::forward_iterator_tag;
        using value_type = std::pair<ITable::student_code&, std::shared_ptr<Student>&>;
        using difference_type = std::ptrdiff_t;
        using pointer = std::pair<ITable::student_code*, std::shared_ptr<Student>*>;
        using reference = std::pair<ITable::student_code&, std::shared_ptr<Student>&>;

        InMemoryTable& parent_;
        Cell* current;
        Cell* end;

    public:
        explicit Iterator(InMemoryTable& parent, Cell* current, Cell* end);

        reference operator*() const  ;

        pointer operator->() const ;

        Iterator& operator++();

        Iterator operator++(int);

        bool operator==(const Iterator& other) const {
            std::shared_lock<std::shared_mutex> lock(this->parent_.mu);
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const  {
            std::shared_lock<std::shared_mutex> lock(this->parent_.mu);
            return !(*this == other);
        }
    };
    size_t size = 0;

    size_t cap = 10;

	Cell* students_;

    std::shared_mutex  mu;

    void grow();

public:


    InMemoryTable():students_(new Cell[cap]) {};
        
    ~InMemoryTable() { delete[] students_;};

    /**
     * @brief Method for addintion of a new student to table
     * 
     * Collisions are avoided by increment
     * 
     * @param key 
     * @param student 
     */
    void add_student(ITable::student_code key, std::shared_ptr<Student> student) override;

    /**
     * @brief Get the student object
     * 
     * @param code 
     * @return std::shared_ptr<Student> 
     */
    std::shared_ptr<Student> get_student(student_code code) override;

    /**
     * @brief Removing student
     * 
     * Collisions are avoided
     * 
     * @param code 
     * @return true 
     * @return false 
     */
    bool remove_student(student_code code) override;

    std::vector<std::shared_ptr<Student>> get_all_students() override;

    /**
     * @brief Same as get_student method
     * 
     * @param code 
     * @return std::shared_ptr<Student> 
     */
    std::shared_ptr<Student> operator[] (student_code code) override;

    Iterator begin() {
        return Iterator(*this, students_, students_ + cap);
    }

    Iterator end() {
        return Iterator(*this, students_ + cap, students_ + cap);
    }
};



