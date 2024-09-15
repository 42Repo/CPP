#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal {
  public:
    Cat(void);
    Cat(std::string type);
    Cat(const Cat &a);
    Cat &operator=(const Cat &a);
    ~Cat(void);
    void makeSound() const;
};
#endif // CAT_H
