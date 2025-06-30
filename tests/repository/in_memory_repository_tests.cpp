#include <catch2/catch.hpp>
#include <in_memory_repository.hpp>
#include <vector>

TEST_CASE("IN_MEMORY_TABLE") {
    auto table = InMemoryTable();
    auto student_codes = std::vector<int>{1, 2, 3};
    auto student_code = 5;
    auto invalid_student_code = 500;
    auto student = std::make_shared<Student>(Student("", static_cast<GroupIndex>(0), static_cast<Department>(0)));
    SECTION("ADD STUDENT") {
        table.add_student(student_code, student);
        REQUIRE( table.get_student(student_code).get() == student.get()  );
        REQUIRE( table[student_code].get() == student.get());
    }
    SECTION("ITERATE") {
        for (auto& code : student_codes) {
            table.add_student(code, student);
        }
        auto idx = 1;
        for (auto it = table.begin(); it != table.end(); ++it, ++idx) {
            REQUIRE( static_cast<int>((*it).first) == idx );
            REQUIRE( (*it).second.get() == student.get() );
        }
    }
    SECTION("DELETE STUDENT") {
        table.add_student(student_code, student);
        auto deleted = table.remove_student(student_code);
        REQUIRE( deleted == true  );
        REQUIRE( table.remove_student(invalid_student_code) == false);
    }
    SECTION("UNKNOWN STUDENT") {
        table.remove_student(student_code);
        REQUIRE( table.get_student(student_code).get() == nullptr );
    }


    
}