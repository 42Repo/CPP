#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { std::cout << "PmergeMe constructor" << std::endl; }

PmergeMe::PmergeMe(const PmergeMe &other) {
    std::cout << "PmergeMe copy constructor" << std::endl;
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    std::cout << "PmergeMe assignation operator" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

PmergeMe::~PmergeMe() { std::cout << "PmergeMe destructor" << std::endl; }
