#pragma once

#include "Bureaucrat.h"
#include "AForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "ShrubberyCreationForm.h"

class Intern {
  public:
	Intern();
	Intern(const Intern &i);
	Intern &operator=(const Intern &i);
	~Intern();
	AForm *createRobotomyRequestForm(const std::string &target);
	AForm *createPresidentialPardonForm(const std::string &target);
	AForm *createShrubberyCreationForm(const std::string &target);
	AForm *makeForm(const std::string &formName, const std::string &target);

	class FormNotFoundException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Intern &i);
