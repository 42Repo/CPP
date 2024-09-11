#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.h"

class Dog : public Animal {
  public:
    Dog(void);
    Dog(std::string type);
    Dog(const Dog &a);
    Dog &operator=(const Dog &a);
    ~Dog(void);
    void makeSound() const override;
};

#endif // __DOG_H__