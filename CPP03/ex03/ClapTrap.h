#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <sstream>
#include <string>

class ClapTrap {
  public:
    ClapTrap(void);
    ClapTrap(std::string name);
    ClapTrap(std::string name, unsigned int hitPoints, unsigned int energyPoints,
             unsigned int attackDamage);
    ClapTrap(const ClapTrap &a);
    ClapTrap &operator=(const ClapTrap &a);
    virtual ~ClapTrap(void);
    void                takeDamage(unsigned int amount);
    void                beRepaired(unsigned int amount);
    virtual void        attack(const std::string &target);
    virtual std::string getName() const;
    virtual std::string show(void) const;

  protected:
    std::string  _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &f);

#endif // CLAPTRAP_H
