#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

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

#endif // __SCAVTRAP_H__