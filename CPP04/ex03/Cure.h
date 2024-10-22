#pragma once

#include "AMateria.h"

class Cure : public AMateria {
  public:
    Cure();
    Cure(const Cure &other);
    Cure &operator=(const Cure &other);
    ~Cure();
    AMateria *clone() const;
    void      use(ICharacter &target);
};
