#include "Animal.h"

Animal::Animal(void) : _type("Unknown") { std::cout << "Animal Default constructor" << std::endl; }

Animal::Animal(std::string type) : _type(type) {
    std::cout << "Animal Parameter constructor" << std::endl;
}

Animal::Animal(const Animal &a) : _type(a._type) {
    std::cout << "Animal Copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &a) {
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &a) {
        _type = a._type;
    }
    return *this;
}

Animal::~Animal(void) { std::cout << "Animal Destructor" << std::endl; }

std::string Animal::getType() const { return _type; }

void Animal::makeSound() const { std::cout << "Animal Sound !" << std::endl; }
