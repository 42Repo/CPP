#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

int main() {

    const Animal *one = new Dog();
    const Animal *two = new Cat();

    delete one; // should not create a leak
    delete two;

    const Animal      *meta = new Animal();
    const Animal      *Doggo = new Dog();
    const Animal      *Catos = new Cat();
    const WrongAnimal *wrong = new WrongCat();

    std::cout << std::endl;
    std::cout << "Meta:" << std::endl;
    meta->makeSound();
    std::cout << std::endl;
    std::cout << "Dog:" << std::endl;
    Doggo->makeSound();
    std::cout << std::endl;
    std::cout << "Cat:" << std::endl;
    Catos->makeSound();
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

    // Main test

    const int size = 10;
    Animal   *animals[size];

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < size; i++) {
        delete animals[i];
    }

    delete cat2;
    delete cat;
    delete wrong;
    delete Catos;
    delete Doggo;
    delete meta;
    return 0;
}
