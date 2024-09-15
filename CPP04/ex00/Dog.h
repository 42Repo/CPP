#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal {
  public:
    Dog(void);
    Dog(std::string type);
    Dog(const Dog &a);
    Dog &operator=(const Dog &a);
    ~Dog(void);
    void makeSound() const;
};

#endif // DOG_H
