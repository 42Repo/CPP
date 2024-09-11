#include "FragTrap.h"

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30) {
    std::cout << "FragTrap Default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap Parameter constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &a) : ClapTrap(a) {
    std::cout << "FragTrap Copy constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &a) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &a) {
        ClapTrap::operator=(a);
    }
    return *this;
}

FragTrap::~FragTrap() { std::cout << "FragTrap Destructor" << std::endl; }

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " high fives guys !" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (_energyPoints <= 0) {
        std::cout << "Not enough energy point" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << target << " take " << _hitPoints << " damage !" << std::endl;
}

std::string FragTrap::show(void) const {
    std::string str = "FragTrap " + _name + " has " + std::to_string(_hitPoints) + " hit points, " +
                      std::to_string(_energyPoints) + " energy points and " +
                      std::to_string(_attackDamage) + " attack damage";
    return (str);
}

std::ostream &operator<<(std::ostream &out, FragTrap const &f) {
    out << f.show();
    return out;
}