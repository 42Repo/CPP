#pragma once

#include "ICharacter.h"

class Character : public ICharacter {
  private:
    std::string _name;
    AMateria   *_materias[4];

  public:
    Character();
    explicit Character(std::string const &name);
    Character(const Character &other);
    Character &operator=(const Character &other);
    ~Character();
    std::string const &getName() const;
    void               equip(AMateria *m);
    void               unequip(int idx);
    void               use(int idx, ICharacter &target);
};
