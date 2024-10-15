#include "Array.h"

int main() {
    Array<int> a(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    a.print();
    Array<int> b(a);
    b.print();
    Array<int> c;
    c = a;
    c.print();
    return 0;
}
