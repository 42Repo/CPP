#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap() {
    c_name = "DefaultScav";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &a) : ClapTrap(a) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &a) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &a) {
        ClapTrap::operator=(a);
    }
    return *this;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor" << std::endl; }

void ScavTrap::guardGate() { std::cout << "ScavTrap is now in Gate keeper mode." << std::endl; }

void ScavTrap::attack(const std::string &target) {
    if (_energyPoints <= 0) {
        std::cout << "Not enough energy points" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << c_name << " attacks " << target << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

std::string ScavTrap::show(void) const {
    std::ostringstream oss;
    oss << "ScavTrap " << c_name << " has " << _hitPoints << " hit points, " << _energyPoints
        << " energy points and " << _attackDamage << " attack damage";
    return oss.str();
}

std::ostream &operator<<(std::ostream &out, ScavTrap const &f) {
    out << f.show();
    return out;
}
