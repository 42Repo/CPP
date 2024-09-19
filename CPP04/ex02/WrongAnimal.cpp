#include "WrongAnimal.h"

WrongAnimal::WrongAnimal(void) : _type("Unknown") {
    std::cout << "WrongAnimal Default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
    std::cout << "WrongAnimal Parameter constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a) : _type(a._type) {
    std::cout << "WrongAnimal Copy constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a) {
    std::cout << "WrongAnimal Copy assignment operator constructor" << std::endl;
    if (this != &a) {
        _type = a._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal(void) { std::cout << "WrongAnimal Destructor" << std::endl; }

std::string WrongAnimal::getType() const { return _type; }

void WrongAnimal::makeSound() const { std::cout << "WrongAnimal Sound !" << std::endl; }
