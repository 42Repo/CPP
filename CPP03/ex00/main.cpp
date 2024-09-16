#include "ClapTrap.h"

int main(void) {
    ClapTrap a;
    ClapTrap b("Morgan");

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    b.takeDamage(3);
    std::cout << b << std::endl;
    b.takeDamage(20);
    std::cout << b << std::endl;
    b.beRepaired(3);
    std::cout << b << std::endl;
    b.attack("Eric");
    b.attack("Eric");
    std::cout << b << std::endl;
    b.attack("Eric");
    std::cout << b << std::endl;
    b.beRepaired(6);
    std::cout << b << std::endl;
    b.attack("Eric");
}
