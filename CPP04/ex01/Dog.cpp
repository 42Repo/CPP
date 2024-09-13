#include "Dog.h"

Dog::Dog(void) : Animal("Dog") { std::cout << "Dog Default constructor" << std::endl; }

Dog::Dog(std::string type) : Animal(type) { std::cout << "Dog Parameter constructor" << std::endl; }

Dog::Dog(const Dog &a) : Animal(a) { std::cout << "Dog Copy constructor" << std::endl; }

Dog &Dog::operator=(const Dog &a) {
    if (this != &a) {
        Animal::operator=(a);
    }
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog(void) { std::cout << "Dog Destructor" << std::endl; }

void Dog::makeSound() const { std::cout << "Woula jsuis un chien !" << std::endl; }
