#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Address of the string: " << &str << std::endl;
    std::cout << "Address of the string using the pointer: " << stringPTR << std::endl;
    std::cout << "Address of the string using the reference: " << &stringREF << std::endl;

    std::cout << std::endl << "String: " << str << std::endl;
    std::cout << "String using the pointer: " << *stringPTR << std::endl;
    std::cout << "String using the reference: " << stringREF << std::endl;
    return 0;
}
