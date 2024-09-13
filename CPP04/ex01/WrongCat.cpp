#include "WrongCat.h"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
    std::cout << "WrongCat Default constructor" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
    std::cout << "WrongCat Parameter constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &a) : WrongAnimal(a) {
    std::cout << "WrongCat Copy constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &a) {
    if (this != &a) {
        WrongAnimal::operator=(a);
    }
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat(void) { std::cout << "WrongCat Destructor" << std::endl; }

void WrongCat::makeSound() const { std::cout << "Miaou le chat !" << std::endl; }
