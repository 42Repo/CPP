#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__

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

#endif // __WRONGCAT_H__