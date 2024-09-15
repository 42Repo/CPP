#ifndef DOG_H
#define DOG_H

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
  public:
    Dog(void);
    Dog(std::string type);
    Dog(const Dog &a);
    Dog &operator=(const Dog &a);
    ~Dog(void);
    void   makeSound() const;
    Brain *getBrain() const;

  private:
    Brain *_brain;
};

#endif // DOG_H
