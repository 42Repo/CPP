#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal {
  public:
    Animal(void);
    Animal(std::string type);
    Animal(const Animal &a);
    Animal &operator=(const Animal &a);
    virtual ~Animal(void);
    virtual void makeSound() const;
    std::string  getType() const;

  protected:
    std::string _type;
};

#endif // ANIMAL_H
