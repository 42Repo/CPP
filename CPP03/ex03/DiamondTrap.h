#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {
  public:
    DiamondTrap();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap();

    void        attack(const std::string &target);
    void        whoAmI();
    std::string show(void) const;

  private:
    std::string _name; // Same as in ClapTrap
};

std::ostream &operator<<(std::ostream &out, DiamondTrap const &f);

#endif // DIAMONDTRAP_H
