#include "iter.h"

template <typename T> void print(T const &x) { std::cout << x << std::endl; }

int main() {
    int         intArray[] = {1, 2, 3, 4, 5};
    float       floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    std::string stringArray[] = {"one", "two", "three", "four", "five"};

    std::cout << "intArray: ";
    ::iter<int>(intArray, sizeof(intArray) / sizeof(intArray[0]), print);
    std::cout << "floatArray: ";
    ::iter<float>(floatArray, sizeof(floatArray) / sizeof(floatArray[0]), print);
    std::cout << "stringArray: ";
    ::iter(stringArray, sizeof(stringArray) / sizeof(stringArray[0]), print);
    return 0;
}
