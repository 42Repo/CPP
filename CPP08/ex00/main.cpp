#include "easyfind.h"
#include <iostream>
#include <list>
#include <vector>

int main() {
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    std::cout << "Vector: ";
    for (unsigned int i = 0; i < 10; i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << "easyfind(v, 0): " << easyfind(v, 0) << std::endl;
    std::cout << "easyfind(v, 5): " << easyfind(v, 5) << std::endl;
    std::cout << "easyfind(v, 9): " << easyfind(v, 9) << std::endl;

    try {
        std::cout << "easyfind(v, 10): " << easyfind(v, 10) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "easyfind(v, 11): " << easyfind(v, 11) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "easyfind(v, -1): " << easyfind(v, -1) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::list<int> l;
    for (int i = 9; i >= 0; i--)
        l.push_back(i);
    std::cout << "List: ";
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "easyfind(l, 5): " << easyfind(l, 5) << std::endl;
    std::cout << "easyfind(l, 0): " << easyfind(l, 0) << std::endl;
    std::cout << "easyfind(l, 9): " << easyfind(l, 9) << std::endl;

    try {
        std::cout << "easyfind(l, 10): " << easyfind(l, 10) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "easyfind(l, 11): " << easyfind(l, 11) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "easyfind(l, -1): " << easyfind(l, -1) << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
