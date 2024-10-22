#include "Character.h"
#include "Cure.h"
#include "Ice.h"
#include "MateriaSource.h"

int main() {
    IMateriaSource *src = new MateriaSource();

    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    src->learnMateria(ice);
    delete ice;
    src->learnMateria(cure);
    delete cure;

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
