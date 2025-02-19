#include "Form.h"

static void testBureaucratCreation() {
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

static void testFormCreation() {
    try {
        Form f1("Form1", 1, 1);
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form f2("Form2", 150, 150);
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form f3("Form3", 0, 1); // Should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form f4("Form4", 1, 151); // Should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

static void testFormSigning() {
    try {
        Bureaucrat b("Bureaucrat", 50);
        Form       f("Form", 100, 100);
        std::cout << b << std::endl;
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bureaucrat", 150);
        Form       f("Form", 100, 100);
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
    testFormCreation();
    testFormSigning();
    return 0;
}
