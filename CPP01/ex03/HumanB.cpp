#include "HumanB.h"

HumanB::HumanB(std::string name) {
    _name = name;
    _weapon = NULL;
    std::cout << _name << " is born without a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
    std::cout << _name << " has now a " << _weapon->getType() << std::endl;
}

void HumanB::attack() {
    if (_weapon == NULL) {
        std::cout << _name << " has no weapon" << std::endl;
        return;
    }
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
