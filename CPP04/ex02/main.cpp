#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

int main() {
    const AAnimal *one = new Dog();
    const AAnimal *two = new Cat();

    std::cout << "Deleting one and two:" << std::endl;
    delete one;
    delete two;

    std::cout << std::endl;
    const AAnimal *Doggo = new Dog();
    const AAnimal *Catos = new Cat();
    const WrongAnimal *wrong = new WrongCat();

    std::cout << "Dog sound:" << std::endl;
    Doggo->makeSound();

    std::cout << "Cat sound:" << std::endl;
    Catos->makeSound();

    std::cout << "WrongCat sound:" << std::endl;
    wrong->makeSound();
    
    std::cout << std::endl;
    const Cat *cat = new Cat();
    const Cat *cat2 = new Cat();
    
    cat->getBrain()->setIdea(0, "Idea 1");
    cat->getBrain()->setIdea(1, "Idea 2");

    cat2->getBrain()->setIdea(0, "Idea 3");
    cat2->getBrain()->setIdea(1, "Idea 4");

    std::cout << "Cat 1 Brain:" << std::endl;
    std::cout << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << cat->getBrain()->getIdea(1) << std::endl;

    std::cout << "Cat 2 Brain:" << std::endl;
    std::cout << cat2->getBrain()->getIdea(0) << std::endl;
    std::cout << cat2->getBrain()->getIdea(1) << std::endl;

    std::cout << std::endl << "Testing copy constructor for Cat:" << std::endl;
    Cat catCopy(*cat);

    std::cout << "CatCopy Brain after copy:" << std::endl;
    std::cout << catCopy.getBrain()->getIdea(0) << std::endl;
    std::cout << catCopy.getBrain()->getIdea(1) << std::endl;

    cat->getBrain()->setIdea(0, "Modified Idea");

    std::cout << "After modifying Cat 1's brain, CatCopy Brain should not change:" << std::endl;
    std::cout << "CatCopy Brain:" << std::endl;
    std::cout << catCopy.getBrain()->getIdea(0) << std::endl;
    std::cout << catCopy.getBrain()->getIdea(1) << std::endl;

    std::cout << "Cat 1 Brain:" << std::endl;
    std::cout << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << cat->getBrain()->getIdea(1) << std::endl;

    std::cout << std::endl << "Testing assignment operator for Cat:" << std::endl;
    Cat assignedCat;
    assignedCat = *cat2;

    std::cout << "Assigned Cat Brain:" << std::endl;
    std::cout << assignedCat.getBrain()->getIdea(0) << std::endl;
    std::cout << assignedCat.getBrain()->getIdea(1) << std::endl;

    const int size = 10;
    AAnimal *AAnimals[size];

    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            AAnimals[i] = new Dog();
        } else {
            AAnimals[i] = new Cat();
        }
    }

    // This don't work because AAnimal is an abstract class
    // AAnimal *wrongAnimal = new AAnimal();

    for (int i = 0; i < size; i++) {
        delete AAnimals[i];
    }

    delete cat2;
    delete cat;
    delete wrong;
    delete Catos;
    delete Doggo;

    return 0;
}
