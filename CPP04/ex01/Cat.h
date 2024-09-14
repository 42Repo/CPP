#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
  public:
    Cat(void);
    Cat(std::string type);
    Cat(const Cat &a);
    Cat &operator=(const Cat &a);
    ~Cat(void);
    void   makeSound() const;
    Brain *getBrain() const;

  private:
    Brain *_brain;
};
#endif // __CAT_H__