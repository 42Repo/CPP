#include "DiamondTrap.h"

DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"),
      ScavTrap(),
      FragTrap(),
      _name("Default") {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(),
      FragTrap(),
      _name(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap Parameter constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other),
      ScavTrap(other),
      FragTrap(other),
      _name(other._name) {
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap Destructor called" << std::endl; }

void DiamondTrap::attack(const std::string &target) { ScavTrap::attack(target); }

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name is " << _name << ", ClapTrap name is " << ClapTrap::_name
              << std::endl;
}

std::string DiamondTrap::getName() const { return _name; }

std::string DiamondTrap::show(void) const {
    std::ostringstream oss;
    oss << "DiamondTrap " << _name << " has " << _hitPoints << " hit points, " << _energyPoints
        << " energy points and " << _attackDamage << " attack damage";
    return oss.str();
}

std::ostream &operator<<(std::ostream &out, DiamondTrap const &f) {
    out << f.show();
    return out;
}
