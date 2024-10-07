#include "Fixed.h"

int main(void) {
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    Fixed d;
    std::cout << std::endl;
    Fixed e(d);
    std::cout << std::endl;
    Fixed f = e;
    std::cout << std::endl;

    return 0;
}
