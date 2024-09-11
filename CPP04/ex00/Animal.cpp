#include "Animal.h"

Animal::Animal(void) : type("Unknown") { std::cout << "Animal Default constructor" << std::endl; }

Animal::Animal(std::string type) : type(type) {
    std::cout << "Animal Parameter constructor" << std::endl;
}

Animal::Animal(const Animal &a) : type(a.type) {
    std::cout << "Animal Copy constructor" << std::endl;
}

Animal &Animal::operator=(const Animal &a) {
    std::cout << "Animal Copy assignment operator constructor" << std::endl;
    if (this != &a) {
        type = a.type;
    }
    return *this;
}

Animal::~Animal(void) { std::cout << "Animal Destructor" << std::endl; }

std::string Animal::getType() const { return type; }

void Animal::makeSound() const { std::cout << "Animal Sound !" << std::endl; }
