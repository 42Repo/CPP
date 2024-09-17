#include "HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
    std::cout << _name << " is born with a " << _weapon.getType() << std::endl;
}

void HumanA::attack() {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
