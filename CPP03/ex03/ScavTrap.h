#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

const int DEFAULT_SCAVTRAP_HIT_POINTS = 100;
const int DEFAULT_SCAVTRAP_ENERGY_POINTS = 50;
const int DEFAULT_SCAVTRAP_ATTACK_DAMAGE = 20;

class ScavTrap : virtual public ClapTrap {
  public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();
    void        guardGate();
    void        attack(const std::string &target);
    std::string show() const;
};

std::ostream &operator<<(std::ostream &out, ScavTrap const &scavtrap);

#endif // SCAVTRAP_H
