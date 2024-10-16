#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
  public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &a);
    ScavTrap &operator=(const ScavTrap &a);
    ~ScavTrap(void);
    void        guardGate();
    void        attack(const std::string &target);
    std::string show(void) const;
};

std::ostream &operator<<(std::ostream &out, ScavTrap const &f);

#endif // SCAVTRAP_H
