#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main() {
    ShrubberyCreationForm  s("Shrubbery");
    RobotomyRequestForm    r("Robotomy");
    PresidentialPardonForm p("Bill Clinton");

    try {
        Bureaucrat b("Bureaucrat", 1);
        std::cout << b << std::endl;

        std::cout << s << std::endl;
        b.signForm(s);
        std::cout << s << std::endl;
        b.executeForm(s);

        std::cout << r << std::endl;
        b.signForm(r);
        std::cout << r << std::endl;
        b.executeForm(r);

        std::cout << p << std::endl;
        b.signForm(p);
        std::cout << p << std::endl;
        b.executeForm(p);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        ShrubberyCreationForm s("Shrubbery");
        Bureaucrat            b("Bureaucrat", 1);

        b.signForm(s);
        b.executeForm(s);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        RobotomyRequestForm r("Robotomy");
        Bureaucrat          b("Bureaucrat", 1);

        b.signForm(r);
        b.executeForm(r);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        PresidentialPardonForm p("Bill Clinton");
        Bureaucrat             b("Bureaucrat", 1);

        b.signForm(p);
        b.executeForm(p);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        ShrubberyCreationForm  s("Shrubbery");
        RobotomyRequestForm    r("Robotomy");
        PresidentialPardonForm p("Bill Clinton");
        Bureaucrat             b("Bureaucrat", 150); // Low grade bureaucrat

        b.signForm(s);
        b.signForm(r);
        b.signForm(p);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        ShrubberyCreationForm  s("Shrubbery");
        RobotomyRequestForm    r("Robotomy");
        PresidentialPardonForm p("Bill Clinton");
        Bureaucrat             highGradeB("HighGradeBureaucrat", 1);

        highGradeB.signForm(s);
        highGradeB.signForm(r);
        highGradeB.signForm(p);

        highGradeB.signForm(s);
        highGradeB.signForm(r);
        highGradeB.signForm(p);

        Bureaucrat b("Bureaucrat", 150); // Low grade bureaucrat
        b.executeForm(s);
        b.executeForm(r);
        b.executeForm(p);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Intern intern;
        AForm *form;

        form = intern.makeForm("robotomy request", "Bender");
        form->beSigned(Bureaucrat("Bureaucrat", 1));
        form->execute(Bureaucrat("Bureaucrat", 1));
        delete form;

        form = intern.makeForm("presidential pardon", "Nixon");
        form->beSigned(Bureaucrat("Bureaucrat", 1));
        form->execute(Bureaucrat("Bureaucrat", 1));
        delete form;

        form = intern.makeForm("shrubbery creation", "Home");
        form->beSigned(Bureaucrat("Bureaucrat", 1));
        form->execute(Bureaucrat("Bureaucrat", 1));
        delete form;

        form = intern.makeForm("unknown form", "Unknown");
        form->beSigned(Bureaucrat("Bureaucrat", 1));
        form->execute(Bureaucrat("Bureaucrat", 1));
        delete form;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
