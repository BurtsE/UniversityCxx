#include "app.hpp"
#include <cli_controller.hpp>

int App::run() {
    
    InMemoryTable t = InMemoryTable();

    auto university = University(t);

    auto controller = CLIController(university);

    try {
        controller.run();
    }
    catch(const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    catch(...) {
        std::cerr << "Fatal error: unknown" << std::endl;
        return 1;
    }
    return 0;
}