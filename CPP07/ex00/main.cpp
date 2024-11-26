#include "whatever.h"
#include <iostream>

int main(void) {
    int first = 2;
    int second = 3;
    ::swap(first, second);
    std::cout << "a = " << first << ", b = " << second << std::endl;
    std::cout << "min( a, b ) = " << ::min(first, second) << std::endl;
    std::cout << "max( a, b ) = " << ::max(first, second) << std::endl;
    std::string first_str = "chaine1";
    std::string second_str = "chaine2";
    ::swap(first_str, second_str);
    std::cout << "c = " << first_str << ", d = " << second_str << std::endl;
    std::cout << "min( c, d ) = " << ::min(first_str, second_str) << std::endl;
    std::cout << "max( c, d ) = " << ::max(first_str, second_str) << std::endl;
    return 0;
}
