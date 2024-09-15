#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
  public:
    WrongCat(void);
    WrongCat(std::string type);
    WrongCat(const WrongCat &a);
    WrongCat &operator=(const WrongCat &a);
    ~WrongCat(void);
    void makeSound() const;
};

#endif // WRONGCAT_H
