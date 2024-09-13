#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.h"

class Cat : public Animal {
  public:
    Cat(void);
    Cat(std::string type);
    Cat(const Cat &a);
    Cat &operator=(const Cat &a);
    ~Cat(void);
    void makeSound() const override;
};
#endif // __CAT_H__