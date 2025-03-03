#include "A.h"
#include "B.h"
#include "C.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

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
        std::cout << "A" << '\n';
    } else if (dynamic_cast<B *>(p) != NULL) {
        std::cout << "B" << '\n';
    } else if (dynamic_cast<C *>(p) != NULL) {
        std::cout << "C" << '\n';
    } else {
        std::cout << "Unknown" << '\n';
    }
}

void identify(Base &p) {
    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << '\n';
    } catch (...) {
    }

    try {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << '\n';
    } catch (...) {
    }

    try {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << '\n';
    } catch (...) {
    }
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    Base *base = generate();
    if (base == NULL) {
        std::cerr << "Error: could not generate a class" << '\n';
        return 1;
    }
    identify(base);
    identify(*base);

    delete base;
    return 0;
}
