#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.h"
#include "ScavTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {
  public:
    DiamondTrap();
    explicit DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap();

    void        attack(const std::string &target);
    void        whoAmI() const;
    std::string getName() const;
    std::string show() const;

  private:
    std::string _name; // Same as in ClapTrap
};

std::ostream &operator<<(std::ostream &out, DiamondTrap const &diamondtrap);

#endif // DIAMONDTRAP_H
