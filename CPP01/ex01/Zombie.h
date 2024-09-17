#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
  public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void setName(std::string name);
    void announce() const;

  private:
    std::string m_name;
};

Zombie *zombieHorde(int N, std::string name);

#endif // ZOMBIE_H
