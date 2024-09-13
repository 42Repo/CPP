#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

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
    std::string type;
};

#endif // __WRONGANIMAL_H__