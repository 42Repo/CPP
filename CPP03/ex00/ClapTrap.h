#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <iostream>
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
    unsigned int _hitPoints = 10;
    unsigned int _energyPoints = 10;
    unsigned int _attackDamage = 0;
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &f);

#endif // __CLAPTRAP_H__