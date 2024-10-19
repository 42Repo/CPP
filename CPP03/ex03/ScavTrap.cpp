#include "ScavTrap.h"
#include <iostream>
#include <sstream>

ScavTrap::ScavTrap() {
    _hitPoints = DEFAULT_SCAVTRAP_HIT_POINTS;
    _energyPoints = DEFAULT_SCAVTRAP_ENERGY_POINTS;
    _attackDamage = DEFAULT_SCAVTRAP_ATTACK_DAMAGE;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    _hitPoints = DEFAULT_SCAVTRAP_HIT_POINTS;
    _energyPoints = DEFAULT_SCAVTRAP_ENERGY_POINTS;
    _attackDamage = DEFAULT_SCAVTRAP_ATTACK_DAMAGE;
    std::cout << "ScavTrap Parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor" << std::endl; }

void ScavTrap::guardGate() const {
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (_energyPoints <= 0) {
        std::cout << "Not enough energy points" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

std::string ScavTrap::show() const {
    std::ostringstream oss;
    oss << "ScavTrap " << _name << " has " << _hitPoints << " hit points, " << _energyPoints
        << " energy points and " << _attackDamage << " attack damage";
    return oss.str();
}

std::ostream &operator<<(std::ostream &out, ScavTrap const &scavtrap) {
    out << scavtrap.show();
    return out;
}
