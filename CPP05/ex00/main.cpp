#include "Bureaucrat.h"

int main() {
    Bureaucrat a("a", 1);
    Bureaucrat b("b", 150);
    Bureaucrat c("c", 75);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    // Should throw exception "Grade too high"
    try {
        Bureaucrat d("d", 0);
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << e.what() << std::endl;
    }

    // Should throw exception "Grade too low"
    try {
        Bureaucrat e("e", 152);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    // Should throw exception "Grade too high"
    try {
        a.incrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Should throw exception "Grade too low"
    try {
        b.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl << "grade a: " << a.getGrade() << std::endl;
    // Should not throw exception
    try {
        a.decrementGrade();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "grade a: " << a.getGrade() << std::endl;


    try {
        Bureaucrat *f = new Bureaucrat("f", 0);
        delete f;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
