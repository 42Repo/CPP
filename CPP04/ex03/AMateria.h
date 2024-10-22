#pragma once

#include <iostream>

class ICharacter;

class AMateria {
  protected:
    std::string _type;

  public:
    AMateria();
    explicit AMateria(std::string const &type);
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();
    std::string const &getType() const;
    virtual AMateria  *clone() const = 0;
    virtual void       use(ICharacter &target);
};
