#include "AForm.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

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

int main() {
    testBureaucratCreation();
    ShrubberyCreationForm s("Shrubbery");

    try {
        Bureaucrat b("Bureaucrat", 1);
        std::cout << b << std::endl;
        s.beSigned(b);
        std::cout << s << std::endl;
        b.executeForm(s);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
