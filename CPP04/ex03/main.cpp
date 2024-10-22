#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "MateriaSource.h"
#include <iostream>

int main() {
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    AMateria   *tmp;
    AMateria   *tmp2;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp2 = src->createMateria("cure");
    me->equip(tmp2);

    ICharacter *bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}
