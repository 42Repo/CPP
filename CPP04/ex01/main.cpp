#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int main() {

    std::cout << "=== Testing Default Constructors ===" << std::endl;
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << "\n=== Testing getType() and makeSound() Methods ===" << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
    dog->makeSound();
    cat->makeSound();

    std::cout << "\n=== Testing Brain Functionality ===" << std::endl;
    Cat *cat1 = new Cat();
    Cat *cat2 = new Cat();

    cat1->getBrain()->setIdea(0, "Chase mice");
    cat1->getBrain()->setIdea(1, "Climb trees");

    cat2->getBrain()->setIdea(0, "Scratch furniture");
    cat2->getBrain()->setIdea(1, "Sleep all day");

    std::cout << "Cat1's ideas:" << std::endl;
    std::cout << "- " << cat1->getBrain()->getIdea(0) << std::endl;
    std::cout << "- " << cat1->getBrain()->getIdea(1) << std::endl;

    std::cout << "Cat2's ideas:" << std::endl;
    std::cout << "- " << cat2->getBrain()->getIdea(0) << std::endl;
    std::cout << "- " << cat2->getBrain()->getIdea(1) << std::endl;

    std::cout << "\n=== Testing Array of Animals ===" << std::endl;
    const int size = 4;
    Animal   *animals[size];

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    std::cout << "\n=== Cleaning Up Array of Animals ===" << std::endl;
    for (int i = 0; i < size; i++) {
        delete animals[i];
    }

    std::cout << "\n=== Testing Deep Copy ===" << std::endl;
    Dog basicDog;
    basicDog.getBrain()->setIdea(0, "Play fetch");

    {
        Dog tmpDog = basicDog;
        std::cout << "tmpDog's idea before change: " << tmpDog.getBrain()->getIdea(0) << std::endl;
        tmpDog.getBrain()->setIdea(0, "Chase tail");
        std::cout << "tmpDog's idea after change: " << tmpDog.getBrain()->getIdea(0) << std::endl;
    }

    std::cout << "basicDog's idea should remain unchanged: " << basicDog.getBrain()->getIdea(0)
              << std::endl;

    std::cout << "\n=== Cleaning Up ===" << std::endl;
    delete cat1;
    delete cat2;
    delete cat;
    delete dog;

    return 0;
}
