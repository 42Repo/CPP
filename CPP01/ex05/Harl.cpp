#include "Harl.h"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::complain(std::string level) {
    void (Harl::*complaints[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*complaints[i])();
            return;
        }
    }
    std::cout << "Unknown level" << std::endl;
}

void Harl::debug(void) { std::cout << "Wow i like debugging so much" << std::endl; }

void Harl::info(void) { std::cout << "That's some useful information" << std::endl; }

void Harl::warning(void) { std::cout << "Be careful" << std::endl; }

void Harl::error(void) { std::cout << "Something horrible happened" << std::endl; }
