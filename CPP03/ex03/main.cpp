#include "DiamondTrap.h"

int main() {
    DiamondTrap dt("Diamondy");

    std::cout << dt << std::endl;

    dt.attack("Enemy");
    dt.whoAmI();

    return 0;
}
