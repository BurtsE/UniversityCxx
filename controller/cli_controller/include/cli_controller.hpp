#pragma once

#include <abstract_controller.hpp>
#include <university.hpp>

class CLIController : public IController {
public:
    CLIController(University& university): university_(university){};
    void run() override;
    void on_create_student() override;
    void on_promote_student() override;
    void on_expel_student() override;
    void on_getting_grades() override;
    void on_setting_grades()  override;


private:
    University& university_;

    template<typename T>
    T get_input(const std::string& prompt);
};