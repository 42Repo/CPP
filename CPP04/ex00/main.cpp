#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

int main() {
    // Test des constructeurs par défaut
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    // Test du constructeur par copie
    Animal copyMeta(*meta);
    Animal copyDog(*j);
    Animal copyCat(*i);

    // Test de l'opérateur d'assignation
    Animal assignMeta = copyMeta;
    Animal assignDog = copyDog;
    Animal assignCat = copyCat;

    // Nettoyage
    delete meta;
    delete j;
    delete i;

    std::cout << "=====================" << std::endl;

    // Test avec WrongAnimal et WrongCat
    const WrongAnimal *meta2 = new WrongAnimal();
    const WrongAnimal *i2 = new WrongCat();

    std::cout << i2->getType() << " " << std::endl;
    i2->makeSound();
    meta2->makeSound();

    // Test du constructeur par copie et de l'assignation pour WrongAnimal
    WrongAnimal copyWrongMeta(*meta2);
    WrongAnimal copyWrongCat(*i2);
    WrongAnimal assignWrongMeta = copyWrongMeta;
    WrongAnimal assignWrongCat = copyWrongCat;

    // Nettoyage
    delete meta2;
    delete i2;

    return 0;
}
