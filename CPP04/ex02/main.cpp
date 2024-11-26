#include "AAnimal.h"
#include "Cat.h"
#include "Dog.h"

int main() {
    std::cout << "\n=== Creating Dog and Cat ===" << std::endl;
    const AAnimal *dog = new Dog();
    const AAnimal *cat = new Cat();

    std::cout << "\n=== Testing makeSound() Method ===" << std::endl;
    dog->makeSound();
    cat->makeSound();

    std::cout << "\n=== Testing Brain Functionality ===" << std::endl;
    Cat *cat1 = new Cat();
    Cat *cat2 = new Cat();

    cat1->getBrain()->setIdea(0, "Eat fish");
    cat1->getBrain()->setIdea(1, "Climb curtains");

    cat2->getBrain()->setIdea(0, "Sleep on keyboard");
    cat2->getBrain()->setIdea(1, "Knock over plants");

    std::cout << "Cat1's ideas:" << std::endl;
    std::cout << "- " << cat1->getBrain()->getIdea(0) << std::endl;
    std::cout << "- " << cat1->getBrain()->getIdea(1) << std::endl;

    std::cout << "Cat2's ideas:" << std::endl;
    std::cout << "- " << cat2->getBrain()->getIdea(0) << std::endl;
    std::cout << "- " << cat2->getBrain()->getIdea(1) << std::endl;

    std::cout << "\n=== Testing Deep Copy with Cat ===" << std::endl;
    Cat catCopy(*cat1);
    std::cout << "catCopy's ideas after copy:" << std::endl;
    std::cout << "- " << catCopy.getBrain()->getIdea(0) << std::endl;
    std::cout << "- " << catCopy.getBrain()->getIdea(1) << std::endl;

    cat1->getBrain()->setIdea(0, "Chase laser pointer");

    std::cout << "cat1's ideas after modification:" << std::endl;
    std::cout << "- " << cat1->getBrain()->getIdea(0) << std::endl;
    std::cout << "- " << cat1->getBrain()->getIdea(1) << std::endl;

    std::cout << "catCopy's ideas should remain unchanged:" << std::endl;
    std::cout << "- " << catCopy.getBrain()->getIdea(0) << std::endl;
    std::cout << "- " << catCopy.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n=== Testing Array of AAnimals ===" << std::endl;
    const int size = 4;
    AAnimal  *animals[size];

    for (int i = 0; i < size; i++) {
        animals[i] =
            (i % 2 == 0) ? static_cast<AAnimal *>(new Dog()) : static_cast<AAnimal *>(new Cat());
    }

    std::cout << "\n=== Cleaning Up Array of AAnimals ===" << std::endl;
    for (int i = 0; i < size; i++) {
        delete animals[i];
    }

    std::cout << "\n=== Cleaning Up ===" << std::endl;
    delete cat2;
    delete cat1;
    delete cat;
    delete dog;

    return 0;
}
