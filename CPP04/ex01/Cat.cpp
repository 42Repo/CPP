#include "Cat.h"

Cat::Cat(void) : Animal("Cat") {
    std::cout << "Cat Default constructor" << std::endl;
    _brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type) {
    std::cout << "Cat Parameter constructor" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat &a) : Animal(a) {
    std::cout << "Cat Copy constructor" << std::endl;
    _brain = new Brain(*a._brain);
}

Cat &Cat::operator=(const Cat &a) {
    if (this != &a) {
        Animal::operator=(a);
        _brain = new Brain(*a._brain);
    }
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat(void) {
    std::cout << "Cat Destructor" << std::endl;
    delete _brain;
}

void Cat::makeSound() const { std::cout << "Miaou le chat !" << std::endl; }

Brain *Cat::getBrain() const { return _brain; }
