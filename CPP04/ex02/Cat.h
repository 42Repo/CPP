#ifndef CAT_H
#define CAT_H

#include "AAnimal.h"
#include "Brain.h"

class Cat : public AAnimal {
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
#endif // CAT_H
