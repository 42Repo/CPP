#include "WrongAnimal.h"

WrongAnimal::WrongAnimal(void) : type("Unknown") {
    std::cout << "WrongAnimal Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
    std::cout << "WrongAnimal Parameter constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a) : type(a.type) {
    std::cout << "WrongAnimal Copy constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a) {
    std::cout << "WrongAnimal Copy assignment operator constructor" << std::endl;
    if (this != &a) {
        type = a.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal(void) { std::cout << "WrongAnimal Destructor" << std::endl; }

std::string WrongAnimal::getType() const { return type; }

void WrongAnimal::makeSound() const { std::cout << "WrongAnimal Sound !" << std::endl; }
