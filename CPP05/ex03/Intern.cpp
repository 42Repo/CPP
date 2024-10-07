#include "Intern.h"

Intern::Intern() {}

Intern::Intern(const Intern &i) { *this = i; }

Intern &Intern::operator=(const Intern &i) {
    (void)i;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::createRobotomyRequestForm(const std::string &target) {
    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) {
    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
    return new PresidentialPardonForm(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) {
    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string formNames[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm *(Intern::*formCreators[])(const std::string &target) = {
        &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm,
        &Intern::createShrubberyCreationForm};

    int formCount = sizeof(formNames) / sizeof(std::string);

    for (int i = 0; i < formCount; ++i) {
        if (formNames[i] == formName) {
            return (this->*(formCreators[i]))(target);
        }
    }

    std::cout << "Intern cannot create " << formName << std::endl;
    throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() { return "Form not found"; }

std::ostream &operator<<(std::ostream &out, const Intern &i) {
    (void)i;
    return out;
}
