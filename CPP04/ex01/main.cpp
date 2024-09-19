#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

// MAIN CPP04 EX01

int main() {

    const Animal* one = new Dog();
    const Animal* two = new Cat();

    delete one; //should not create a leak
    delete two;

    const Animal      *meta = new Animal();
    const Animal      *j = new Dog();
    const Animal      *i = new Cat();
    const WrongAnimal *wrong = new WrongCat();

    std::cout << std::endl;
    std::cout << "Meta:" << std::endl;
    meta->makeSound();
    std::cout << std::endl;
    std::cout << "Dog:" << std::endl;
    j->makeSound();
    std::cout << std::endl;
    std::cout << "Cat:" << std::endl;
    i->makeSound();
    std::cout << std::endl;
    std::cout << "WrongCat:" << std::endl;
    wrong->makeSound();
    std::cout << std::endl;

    // idea test

    const Cat *cat = new Cat();
    const Cat *cat2 = new Cat();
    cat->getBrain()->setIdea(0, "Idea 1");
    cat->getBrain()->setIdea(1, "Idea 2");

    cat2->getBrain()->setIdea(0, "Idea 3");
    cat2->getBrain()->setIdea(1, "Idea 4");

    std::cout << "Cat 1 Brain:" << std::endl;
    std::cout << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << cat->getBrain()->getIdea(1) << std::endl;
    std::cout << std::endl;

    std::cout << "Cat 2 Brain:" << std::endl;
    std::cout << cat2->getBrain()->getIdea(0) << std::endl;
    std::cout << cat2->getBrain()->getIdea(1) << std::endl;

    delete cat2;
    delete cat;
    delete wrong;
    delete i;
    delete j;
    delete meta;
    return 0;
}
