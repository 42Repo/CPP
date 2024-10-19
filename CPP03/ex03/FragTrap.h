#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

const int DEFAULT_FRAGTRAP_HIT_POINTS = 100;
const int DEFAULT_FRAGTRAP_ENERGY_POINTS = 100;
const int DEFAULT_FRAGTRAP_ATTACK_DAMAGE = 30;

class FragTrap : virtual public ClapTrap {
  public:
    FragTrap();
    FragTrap(int diamondConstructor);
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();
    void        highFivesGuys() const;
    void        attack(const std::string &target);
    std::string show() const;
};

std::ostream &operator<<(std::ostream &out, FragTrap const &fragtrap);

#endif // FRAGTRAP_H
