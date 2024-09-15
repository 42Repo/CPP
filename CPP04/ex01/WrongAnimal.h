#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
  public:
    WrongAnimal(void);
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &a);
    WrongAnimal &operator=(const WrongAnimal &a);
    virtual ~WrongAnimal(void);
    void        makeSound() const;
    std::string getType() const;

  protected:
    std::string _type;
};

#endif // WRONGANIMAL_H
