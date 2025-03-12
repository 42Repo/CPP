#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
    (void)argc;
    try {
        PmergeMe pmergeMe(argv);
        pmergeMe.sortAndDisplay();
    } catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
    }
    return 0;
}
