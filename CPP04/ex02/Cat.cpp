#include "Cat.h"

Cat::Cat(void) : AAnimal("Cat"), _brain(new Brain()) {
    std::cout << "Cat Default constructor" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type), _brain(new Brain()) {
    std::cout << "Cat Parameter constructor" << std::endl;
}

Cat::Cat(const Cat &a) : AAnimal(a), _brain(new Brain(*a._brain)) {
    std::cout << "Cat Copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &a) {
    if (this != &a) {
        AAnimal::operator=(a);
        delete _brain;
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
