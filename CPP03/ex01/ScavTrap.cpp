#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap("DefaultScav", 100, 50, 20) {
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
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
        std::cout << "Not enough energy point" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << target << " take " << _hitPoints << " damage !" << std::endl;
}

std::string ScavTrap::show(void) const {
    std::ostringstream oss;
    oss << "ScavTrap " << _name << " has " << _hitPoints << " hit points, " << _energyPoints
        << " energy points and " << _attackDamage << " attack damage";
    return oss.str();
}

std::ostream &operator<<(std::ostream &out, ScavTrap const &f) {
    out << f.show();
    return out;
}
