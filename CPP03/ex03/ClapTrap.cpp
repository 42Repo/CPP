#include "ClapTrap.h"
#include <iostream>
#include <sstream>

ClapTrap::ClapTrap()
    : _name("DefaultClap"),
      _hitPoints(DEFAULT_CLAPTRAP_HIT_POINTS),
      _energyPoints(DEFAULT_CLAPTRAP_ENERGY_POINTS),
      _attackDamage(DEFAULT_CLAPTRAP_ATTACK_DAMAGE) {
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name)
    : _name(name),
      _hitPoints(DEFAULT_CLAPTRAP_HIT_POINTS),
      _energyPoints(DEFAULT_CLAPTRAP_ENERGY_POINTS),
      _attackDamage(DEFAULT_CLAPTRAP_ATTACK_DAMAGE) {
    std::cout << "ClapTrap Parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, const unsigned int hitPoints,
                   const unsigned int energyPoints, const unsigned int attackDamage)
    : _name(name),
      _hitPoints(hitPoints),
      _energyPoints(energyPoints),
      _attackDamage(attackDamage) {
    std::cout << "ClapTrap Parameter constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name),
      _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints),
      _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap Destructor" << std::endl; }

void ClapTrap::attack(const std::string &target) {
    if (_energyPoints <= 0 || _hitPoints <= 0) {
        std::cout << _name << " has no energy or is already dead and can't attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(const unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << _name << " is already dead!" << std::endl;
        return;
    }
    if (amount >= _hitPoints) {
        _hitPoints = 0;
        std::cout << _name << " took " << amount << " damage and is now dead!" << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout << _name << " took " << amount << " damage! Remaining HP: " << _hitPoints
                  << std::endl;
    }
}

void ClapTrap::beRepaired(const unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << _name << " is already dead and cannot be repaired!" << std::endl;
        return;
    }
    if (_energyPoints <= 0) {
        std::cout << _name << " has no energy left to be repaired!" << std::endl;
        return;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << _name << " is repaired by " << amount << " hit points!" << std::endl;
}

std::string ClapTrap::getName() const { return _name; }

std::string ClapTrap::show() const {
    std::ostringstream oss;
    oss << "ClapTrap " << _name << " has " << _hitPoints << " hit points, " << _energyPoints
        << " energy points and " << _attackDamage << " attack damage";
    return oss.str();
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &claptrap) {
    out << claptrap.show();
    return (out);
}
