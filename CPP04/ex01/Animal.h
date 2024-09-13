#ifndef __ANIMAL_H__
#define __ANIMAL_H__

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
    std::string type;
};

#endif // __ANIMAL_H__