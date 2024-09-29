#include "AForm.h"

void testBureaucratCreation() {
    try {
        Bureaucrat b1("Bureaucrat1", 1);
        std::cout << b1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bureaucrat2", 150);
        std::cout << b2 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Bureaucrat3", 0); // Should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Bureaucrat4", 151); // Should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void testAFormCreation() {
    try {
        AForm f1("AForm1", 1, 1);
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        AForm f2("AForm2", 150, 150);
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        AForm f3("AForm3", 0, 1); // Should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        AForm f4("AForm4", 1, 151); // Should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void testAFormSigning() {
    try {
        Bureaucrat b("Bureaucrat", 50);
        AForm       f("AForm", 100, 100);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bureaucrat", 150);
        AForm       f("AForm", 100, 100);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f); // Should fail to sign
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    testBureaucratCreation();
    testAFormCreation();
    testAFormSigning();
    return 0;
}
