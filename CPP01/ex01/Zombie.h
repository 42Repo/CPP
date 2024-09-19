#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
  public:
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    void setName(std::string name);
    void announce(void) const;

  private:
    std::string m_name;
};

Zombie *zombieHorde(int N, std::string name);

#endif // ZOMBIE_H
