#include "Dog.h"

Dog::Dog(void) : Animal("Dog"), _brain(new Brain()) {
    std::cout << "Dog Default constructor" << std::endl;
}

Dog::Dog(std::string type) : Animal(type), _brain(new Brain()) {
    std::cout << "Dog Parameter constructor" << std::endl;
}

Dog::Dog(const Dog &a) : Animal(a), _brain(new Brain(*a._brain)) {
    std::cout << "Dog Copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &a) {
    if (this != &a) {
        Animal::operator=(a);
        delete _brain;
        _brain = new Brain(*a._brain);
    }
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog(void) {
    std::cout << "Dog Destructor" << std::endl;
    delete _brain;
}

void Dog::makeSound() const { std::cout << "Woula jsuis un chien !" << std::endl; }

Brain *Dog::getBrain() const { return _brain; }
