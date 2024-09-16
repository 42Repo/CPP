#include "ClapTrap.h"

ClapTrap::ClapTrap(void)
    : _name("Default Name"),
      _hitPoints(10),
      _energyPoints(10),
      _attackDamage(0) {
    std::cout << "ClapTrap Default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name),
      _hitPoints(10),
      _energyPoints(10),
      _attackDamage(0) {
    std::cout << "ClapTrap Parameter constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &a)
    : _name(a._name),
      _hitPoints(a._hitPoints),
      _energyPoints(a._energyPoints),
      _attackDamage(a._attackDamage) {
    std::cout << "ClapTrap Copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &a) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &a) {
        _name = a._name;
        _hitPoints = a._hitPoints;
        _energyPoints = a._energyPoints;
        _attackDamage = a._attackDamage;
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
    std::ostringstream oss;
    oss << "ClapTrap " << _name << " has " << _hitPoints << " hit points, " << _energyPoints
        << " energy points and " << _attackDamage << " attack damage";
    return oss.str();
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &f) {
    out << f.show();
    return (out);
}
