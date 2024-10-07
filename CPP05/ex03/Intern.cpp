#include "Intern.h"

Intern::Intern() {}

Intern::Intern(const Intern &i) {
	*this = i;
}

Intern &Intern::operator=(const Intern &i) {
	(void)i;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	if (formName == "robotomy request") {
		std::cout << "Intern creates " << formName << std::endl;
		return new RobotomyRequestForm(target);
	} else if (formName == "presidential pardon") {
		std::cout << "Intern creates " << formName << std::endl;
		return new PresidentialPardonForm(target);
	} else if (formName == "shrubbery creation") {
		std::cout << "Intern creates " << formName << std::endl;
		return new ShrubberyCreationForm(target);
	} else {
		std::cout << "Intern cannot create " << formName << std::endl;
		throw Intern::FormNotFoundException();
		return NULL;
	}
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}

std::ostream &operator<<(std::ostream &out, const Intern &i) {
	(void)i;
	return out;
}
