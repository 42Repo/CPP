#include "AAnimal.h"

AAnimal::AAnimal(void) : _type("Unknown") { std::cout << "AAnimal Default constructor" << std::endl; }

AAnimal::AAnimal(std::string type) : _type(type) {
    std::cout << "AAnimal Parameter constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &a) : _type(a._type) {
    std::cout << "AAnimal Copy constructor" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &a) {
    std::cout << "AAnimal Copy assignment operator constructor" << std::endl;
    if (this != &a) {
        _type = a._type;
    }
    return *this;
}

AAnimal::~AAnimal(void) { std::cout << "AAnimal Destructor" << std::endl; }

std::string AAnimal::getType() const { return _type; }
