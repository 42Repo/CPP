#include "FragTrap.h"

int main(void) {
    // ClapTrap a("ClapTrap");
    // ClapTrap b(a);
    // ClapTrap c = b;
    // ClapTrap d;
    // d = c;

    FragTrap e("Billy");
    FragTrap f(e);
    FragTrap g = f;
    FragTrap h;
    h = g;

    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << c << std::endl;
    // std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    std::cout << g << std::endl;
    std::cout << h << std::endl;

    e.highFivesGuys();
    return 0;
}
