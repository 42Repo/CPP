#include "ScavTrap.h"

int main(void) {
    ClapTrap a("ClapTrap");
    ClapTrap b(a);
    ClapTrap c = b;
    ClapTrap d;
    d = c;
    std::cout << a.show() << std::endl;
    std::cout << b.show() << std::endl;
    std::cout << c.show() << std::endl;
    std::cout << d.show() << std::endl;

    ScavTrap e("ScavTrap");
    ScavTrap f(e);
    ScavTrap g = f;
    ScavTrap h;
    h = g;
    std::cout << e.show() << std::endl;
    std::cout << f.show() << std::endl;
    std::cout << g.show() << std::endl;
    std::cout << h.show() << std::endl;

    std::cout << "ScavTrap attack" << std::endl;
    e.attack("target");
    std::cout << "ScavTrap guardGate" << std::endl;
    e.guardGate();
    return 0;
}
