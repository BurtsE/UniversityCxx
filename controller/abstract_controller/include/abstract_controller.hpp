#pragma once

class IController {
public:
    virtual ~IController() = default;

    virtual void run() = 0;
    virtual void on_create_student() = 0;
    virtual void on_promote_student() = 0;
    virtual void on_expel_student() = 0;
    virtual void on_getting_grades() = 0;
    virtual void on_setting_grades() = 0;
};