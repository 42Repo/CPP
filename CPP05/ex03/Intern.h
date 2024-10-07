#pragma once

#include "AForm.h"
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
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
