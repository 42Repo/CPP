#include "FragTrap.h"
#include <iostream>
#include <sstream>

FragTrap::FragTrap() {
    _hitPoints = DEFAULT_FRAGTRAP_HIT_POINTS;
    _energyPoints = DEFAULT_FRAGTRAP_ENERGY_POINTS;
    _attackDamage = DEFAULT_FRAGTRAP_ATTACK_DAMAGE;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    _name = name;
    _hitPoints = DEFAULT_FRAGTRAP_HIT_POINTS;
    _energyPoints = DEFAULT_FRAGTRAP_ENERGY_POINTS;
    _attackDamage = DEFAULT_FRAGTRAP_ATTACK_DAMAGE;
    std::cout << "FragTrap Parameter constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap::FragTrap(const int diamondConstructor) {
    (void)diamondConstructor;
    _hitPoints = DEFAULT_FRAGTRAP_HIT_POINTS;
    _attackDamage = DEFAULT_FRAGTRAP_ATTACK_DAMAGE;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap() { std::cout << "FragTrap Destructor" << std::endl; }

void FragTrap::highFivesGuys() const {
    std::cout << "FragTrap " << _name << " high fives guys !" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (_energyPoints <= 0 || _hitPoints <= 0) {
        std::cout << _name << " has no energy or is already dead and can't attack!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

std::string FragTrap::show() const {
    std::ostringstream oss;
    oss << "FragTrap " << _name << " has " << _hitPoints << " hit points, " << _energyPoints
        << " energy points and " << _attackDamage << " attack damage";
    return oss.str();
}

std::ostream &operator<<(std::ostream &out, FragTrap const &fragtrap) {
    out << fragtrap.show();
    return out;
}
