#include "AMateria.h"
#include "Character.h"
#include "Cure.h"
#include "IMateriaSource.h"
#include "Ice.h"
#include "MateriaSource.h"

int main() {

    std::cout << "=== Creating MateriaSource and Learning Materias ===" << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n=== Creating Characters ===" << std::endl;
    ICharacter *me = new Character("Player");
    ICharacter *bob = new Character("Bob");

    std::cout << "\n=== Equipping Materias ===" << std::endl;
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n=== Using Materias ===" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n=== Unequipping and Testing Empty Slot ===" << std::endl;
    me->unequip(1);
    me->use(1, *bob);

    std::cout << "\n=== Testing Equipping More than 4 Materias ===" << std::endl;
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->equip(src->createMateria("ice"));
    AMateria *tmp2 = src->createMateria("cure");
    me->equip(tmp2);
    delete tmp2;

    std::cout << "\n=== Using All Equipped Materias ===" << std::endl;
    for (int i = 0; i < 4; i++) {
        me->use(i, *bob);
    }

    std::cout << "\n=== Cleaning Up ===" << std::endl;
    delete tmp;
    delete bob;
    delete me;
    delete src;

    return 0;
}
