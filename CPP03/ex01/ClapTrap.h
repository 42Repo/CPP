#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <iostream>
#include <string>

class ClapTrap {
  public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints,
             unsigned int attackDamage);
    ClapTrap(const ClapTrap &a);
    ClapTrap &operator=(const ClapTrap &a);
    ~ClapTrap(void);
    void        attack(const std::string &target);
    void        takeDamage(unsigned int amount);
    void        beRepaired(unsigned int amount);
    std::string show(void) const;

  protected:
    std::string  _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &f);

#endif // __CLAPTRAP_H__