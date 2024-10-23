#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main() {

    std::cout << "=== Testing Default Constructors ===" << std::endl;
    const Animal *animal = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    std::cout << "\n=== Testing getType() Method ===" << std::endl;
    std::cout << "Animal type: " << animal->getType() << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "\n=== Testing makeSound() Method ===" << std::endl;
    animal->makeSound();
    dog->makeSound();
    cat->makeSound();

    std::cout << "\n=== Testing Copy Constructors ===" << std::endl;
    Animal animalCopy(*animal);
    Dog    dogCopy(*dynamic_cast<const Dog *>(dog));
    Cat    catCopy(*dynamic_cast<const Cat *>(cat));

    std::cout << "\n=== Testing Assignment Operators ===" << std::endl;
    Animal animalAssign;
    animalAssign = animalCopy;
    Dog dogAssign;
    dogAssign = dogCopy;
    Cat catAssign;
    catAssign = catCopy;

    std::cout << "\n=== Cleaning Up ===" << std::endl;
    delete animal;
    delete dog;
    delete cat;

    std::cout << "\n=====================\n" << std::endl;

    std::cout << "=== Testing WrongAnimal and WrongCat ===" << std::endl;
    const WrongAnimal *wrongAnimal = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    std::cout << "\n=== Testing getType() Method ===" << std::endl;
    std::cout << "WrongAnimal type: " << wrongAnimal->getType() << std::endl;
    std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;

    std::cout << "\n=== Testing makeSound() Method ===" << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound();

    std::cout << "\n=== Testing Copy Constructors and Assignment Operators ===" << std::endl;
    WrongAnimal wrongAnimalCopy(*wrongAnimal);
    WrongCat    wrongCatCopy(*static_cast<const WrongCat *>(wrongCat));

    WrongAnimal wrongAnimalAssign;
    wrongAnimalAssign = wrongAnimalCopy;
    WrongCat wrongCatAssign;
    wrongCatAssign = wrongCatCopy;

    std::cout << "\n=== Cleaning Up ===" << std::endl;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
