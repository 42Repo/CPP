#include "ClapTrap.h"

ClapTrap::ClapTrap(void) : _name("Default Name") {
    std::cout << "ClapTrap Default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
    std::cout << "ClapTrap Parameter constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &a)
    : _name(a._name),
      _attackDamage(a._attackDamage),
      _energyPoints(a._energyPoints),
      _hitPoints(a._hitPoints) {
    std::cout << "ClapTrap Copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &a) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a) {
        _name = a._name;
        _attackDamage = a._attackDamage;
        _energyPoints = a._energyPoints;
        _hitPoints = a._hitPoints;
    }
    return *this;
}

ClapTrap::~ClapTrap(void) { std::cout << "ClapTrap Destructor" << std::endl; }

void ClapTrap::attack(const std::string &target) {
    if (_energyPoints <= 0) {
        std::cout << "Not enough energy point" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << target << " take " << _hitPoints << " damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << _name << " is already dead !" << std::endl;
    }
    if (amount > _hitPoints) {
        _hitPoints = 0;
        std::cout << _name << " take " << amount << "damage ! He's now dead" << std::endl;
        return;
    }
    _hitPoints -= amount;
    std::cout << _name << " take " << amount << " damage !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0 && _energyPoints <= 0) {
        std::cout << _name << " is already dead !" << std::endl;
    }
    _hitPoints += amount;
    std::cout << _name << " is repaired by " << amount << " points !" << std::endl;
}

std::string ClapTrap::show(void) const {
    std::string str = "ClapTrap " + _name + " has " + std::to_string(_hitPoints) + " hit points, " +
                      std::to_string(_energyPoints) + " energy points and " +
                      std::to_string(_attackDamage) + " attack damage";
    return (str);
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &f) {
    out << f.show();
    return (out);
}