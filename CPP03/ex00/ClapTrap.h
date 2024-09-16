#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <sstream>
#include <string>

class ClapTrap {
  public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &a);
    ClapTrap &operator=(const ClapTrap &a);
    ~ClapTrap(void);
    void        attack(const std::string &target);
    void        takeDamage(unsigned int amount);
    void        beRepaired(unsigned int amount);
    std::string show(void) const;

  private:
    std::string  _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &f);

#endif // CLAPTRAP_H
