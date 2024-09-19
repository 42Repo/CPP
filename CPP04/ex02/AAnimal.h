#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>

class AAnimal {
  public:
    AAnimal(void);
    AAnimal(std::string type);
    AAnimal(const AAnimal &a);
    AAnimal &operator=(const AAnimal &a);
    virtual ~AAnimal(void);
    virtual void makeSound() const = 0;
    std::string  getType() const;

  protected:
    std::string _type;
};

#endif // AANIMAL_H
