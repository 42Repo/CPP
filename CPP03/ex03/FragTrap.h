#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.h"

class FragTrap : virtual public ClapTrap {
  public:
    FragTrap(void);
    FragTrap(std::string name);
    FragTrap(const FragTrap &a);
    FragTrap &operator=(const FragTrap &a);
    ~FragTrap(void);
    void        highFivesGuys(void);
    void        attack(const std::string &target);
    std::string show(void) const;
};

std::ostream &operator<<(std::ostream &out, FragTrap const &f);

#endif // FRAGTRAP_H
