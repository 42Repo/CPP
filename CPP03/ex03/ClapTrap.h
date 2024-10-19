#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <sstream>
#include <string>

class ClapTrap {
  public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const std::string &name, unsigned int hitPoints, unsigned int energyPoints,
             unsigned int attackDamage);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    virtual ~ClapTrap();
    void                takeDamage(unsigned int amount);
    void                beRepaired(unsigned int amount);
    virtual void        attack(const std::string &target);
    virtual std::string getName() const;
    virtual std::string show() const;

  protected:
    std::string  _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &claptrap);

#endif // CLAPTRAP_H
