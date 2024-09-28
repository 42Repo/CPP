#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : _name("default"), _grade(75) {}

Bureaucrat::Bureaucrat(std::string name, int16_t grade) : _name(name) {
    if (grade < MAX_GRADE)
        throw GradeTooHighException();
    else if (grade > MIN_GRADE)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &a) : _name(a._name), _grade(a._grade) {}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return _name; }

int16_t Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
    if (_grade == MAX_GRADE)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade == MIN_GRADE)
        throw GradeTooLowException();
    _grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &a) {
    out << a.getName() << ", bureaucrat grade " << a.getGrade();
    return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }
