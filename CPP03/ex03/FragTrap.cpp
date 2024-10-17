#include "FragTrap.h"

FragTrap::FragTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Parameter constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &a) : ClapTrap(a) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
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
        std::cout << "Not enough energy points" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

std::string FragTrap::show(void) const {
    std::ostringstream oss;
    oss << "FragTrap " << _name << " has " << _hitPoints << " hit points, " << _energyPoints
        << " energy points and " << _attackDamage << " attack damage";
    return oss.str();
}

std::ostream &operator<<(std::ostream &out, FragTrap const &f) {
    out << f.show();
    return out;
}
