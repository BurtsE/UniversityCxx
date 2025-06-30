#include <in_memory_repository.hpp>

#include <ranges>
#include <vector>
#include <thread>



void InMemoryTable::grow(){
    size_t newCap = cap * 2;
    if (cap == newCap ) throw std::overflow_error("table is unable to grow");
    Cell* new_values = new Cell[newCap];
    for (size_t i = 0; i < cap; i++) {
        if (students_[i].student().get() != nullptr) {
            auto idx = students_[i].get_key() % newCap;
            while (!new_values[idx].is_empty()) {
                idx++;
                if (idx==cap) {
                    idx = 0;
                }
            }
            new_values[idx] = std::move(students_[i]);
        }
    }
    delete[] students_;  
    students_ = new_values;
    cap = newCap;
}


void InMemoryTable::add_student(ITable::student_code key,std::shared_ptr<Student> student) {
    std::lock_guard<std::shared_mutex> lock(mu);

    if (size >= cap / 4 * 3) {
        grow();
    }
    auto cell = Cell(key, student);
    auto idx = key % cap;

    while (students_[idx].student().get() != nullptr) {
        if (students_[idx].get_key() == key) {
            students_[idx] = cell;
            size++;
            return;
        }
        idx++;
        if (idx == cap) idx = 0;
    };
    students_[idx] = cell;
    size++;
    return;
}


std::shared_ptr<Student> InMemoryTable::get_student(ITable::student_code code){
    std::shared_lock<std::shared_mutex> lock(mu);
    auto idx = code % cap;
    while (!students_[idx].is_empty()) {
        if (students_[idx].get_key() == code) {
            return students_[idx].student();
        }
        idx++;
        if (idx == cap) idx = 0;
        else if (idx == code%cap) break;
    };
    return nullptr;
}


bool InMemoryTable::remove_student(ITable::student_code code) {
    std::lock_guard<std::shared_mutex> lock(mu);

    auto idx = code%cap;
    while(!students_[idx].is_empty()) {
        if (students_[idx].get_key() == code) {
            students_[idx].remove();
            return true;
        }
        idx++;
        if (idx == cap) idx = 0;
        else if (idx == code%cap) return false;
    }
    return false;
}

std::vector<std::shared_ptr<Student>> InMemoryTable::get_all_students() {
    std::shared_lock<std::shared_mutex> lock(mu);

    std::vector<std::shared_ptr<Student>> students;
    for (size_t i = 0; i < cap; ++i) {
        if (students_[i].student().get() != nullptr) {
            students.push_back(students_[i].student());
        }
    }
    return students;
}


std::shared_ptr<Student> InMemoryTable::operator[](ITable::student_code code){
    std::shared_lock<std::shared_mutex> lock(mu);
    auto idx = code % cap;
    while (!students_[idx].is_empty()) {
        if (students_[idx].get_key() == code) {
            return students_[idx].student();
        }
        idx++;
        if (idx == cap) idx = 0;
        else if (idx == code%cap) break;
    };
    return nullptr;
}


InMemoryTable::Iterator::Iterator(InMemoryTable& parent, Cell* _current, Cell* end) :
    parent_(parent), current(_current), end(end){
    std::shared_lock<std::shared_mutex> lock(this->parent_.mu);
    while (current != end && current->student().get() == nullptr) {
        current++;
    }
}

InMemoryTable::Iterator::reference InMemoryTable::Iterator::operator*() const {
    std::shared_lock<std::shared_mutex> lock(this->parent_.mu);
    auto key = current->get_key();
    auto value = current->student();
    return {key, value};
}

InMemoryTable::Iterator::pointer InMemoryTable::Iterator::operator->() const {
    std::shared_lock<std::shared_mutex> lock(this->parent_.mu);
    auto key = current->get_key();
    auto value = current->student();
    return {&key, &value};
}

InMemoryTable::Iterator& InMemoryTable::Iterator::operator++()  {
    std::shared_lock<std::shared_mutex> lock(this->parent_.mu);

    do {
        ++current;
    } while (current != end && current->student().get() == nullptr);
    return *this;
}

InMemoryTable::Iterator InMemoryTable::Iterator::operator++(int)  {
    std::shared_lock<std::shared_mutex> lock(this->parent_.mu);
    do {
        ++current;
    } while (current != end && current->student().get() == nullptr);
    return (*this);
}