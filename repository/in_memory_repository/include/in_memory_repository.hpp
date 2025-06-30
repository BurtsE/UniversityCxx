#pragma once

#include <table.hpp>
#include <student.hpp>
#include <shared_mutex>
#include <mutex>


class InMemoryTable: public ITable {

private:  

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

        bool is_empty() { return value.get() == nullptr && !is_deleted; }

        void remove() { value = nullptr; is_deleted = true; }
    };
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

    void add_student(ITable::student_code key, std::shared_ptr<Student> student) override;

    std::shared_ptr<Student> get_student(student_code code) override;

    bool remove_student(student_code code) override;

    std::vector<std::shared_ptr<Student>> get_all_students() override;

    std::shared_ptr<Student> operator[] (student_code code) override;

    Iterator begin() {
        return Iterator(*this, students_, students_ + cap);
    }

    Iterator end() {
        return Iterator(*this, students_ + cap, students_ + cap);
    }
};



