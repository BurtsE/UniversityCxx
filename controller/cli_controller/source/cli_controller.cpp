#include "cli_controller.hpp"

#include <sstream>


template<typename T>
T CLIController::get_input(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);

        if (std::cin.bad()) {
            throw std::runtime_error("Broken input");
        }

        if (std::cin.eof()) {
            throw std::runtime_error("EOF");
        }
        
        std::stringstream ss(input);
        if (ss >> value) {
            return value;
        }
        // view_.show_error("Invalid input, please try again");
    }
}

void CLIController::run() {
    while (true) {
        std::cout << "\nUniveristy  System Menu:\n"
                  << "1. Add Student\n"
                  << "2. Promote Student\n"
                  << "3. Expel Student\n"
                  << "4. Get mean grades for each group\n"
                  << "5. Set student's grade\n"
                  << "6. Exit\n";
        
        int choice = get_input<int>("Enter choice: ");

        switch (choice) {
            case 1: on_create_student(); break;
            case 2: on_promote_student(); break;
            case 3: on_expel_student(); break;
            case 4: on_getting_grades(); break;
            case 5: on_setting_grades(); break;
            case 6: return;
            default: std::cerr << "Error: " << "Invalid choice" << std::endl;
                break;
        }
    }
}

void CLIController::on_create_student() {
    try {
        auto student_name = get_input<std::string>("Enter student name: ");

        auto group = static_cast<GroupIndex>(get_input<uint>(
            "Enter student group index (1: A, 2: B, 3: C, 4: D, 5: E, 6: F): ") 
            -1
        );

        auto department = static_cast<Department>(get_input<uint>(
            "Enter department (1: PK, 2: MT): ")
            -1
        );
        
        auto student_code = university_.admission(student_name, group, department);

        std::cout << "Student created successfully!" << std::endl;

        std::cout << "Student name: " << student_name << std::endl;

        std::cout << "Student code: " << student_code << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CLIController::on_promote_student() {

    try {

        auto student_code = get_input<ITable::student_code>("Enter student code to promote: ");

        university_.promote_student(student_code);

        std::cout << "Student promoted successfully!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CLIController::on_expel_student() {
    try {

        auto student_code = get_input<ITable::student_code>("Enter student code to expel: ");

        university_.expel_student(student_code);

        std::cout << "Student expelled" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CLIController::on_getting_grades() {
    try {

        for (auto d = Department::PK; d != Department::LAST; ++d) {

            auto grades = university_.get_group_grades(d);

            std::cout << "Students grades per group for " << d << ": " << std::endl;

            for (auto grade: grades) {
                if (grade.second != 0) {
                    std::cout << grade.first << " " << grade.second << std::endl;
                } 
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void CLIController::on_setting_grades()  {
    try {

        auto student_code = get_input<ITable::student_code>("Enter student code to set grade: ");

        auto subject = get_input<unsigned>("Enter subject number: ");

        auto grade = get_input<unsigned>("Enter grade: ");
        
        university_.set_student_session_grade(student_code, subject, grade);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}