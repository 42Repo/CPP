#include "DiamondTrap.h"
#include <iostream>

int main() {
    DiamondTrap dts("Diamondy");

    std::cout << dts << std::endl;

    dts.attack("Enemy");
    dts.whoAmI();

    return 0;
}
