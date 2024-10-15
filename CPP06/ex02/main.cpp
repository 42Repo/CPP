#include "A.h"
#include "B.h"
#include "C.h"
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

Base *generate(void);
void  identify(Base *p);
void  identify(Base &p);

Base *generate(void) {
    int random = rand() % 3;
    switch (random) {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        return NULL;
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(p) != NULL) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base &p) {
    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (...) {
    }

    try {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
    } catch (...) {
    }

    try {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
    } catch (...) {
    }
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    Base *base = generate();
    if (base == NULL) {
        std::cerr << "Error: could not generate a class" << std::endl;
        return 1;
    }
    identify(base);
    identify(*base);

    delete base;
    return 0;
}
