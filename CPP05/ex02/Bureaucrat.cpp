#include "Bureaucrat.h"
#include "AForm.h"

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

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cerr << _name << " couldn’t sign " << form.getName() << " because of " << e.what()
                  << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cerr << _name << " couldn’t execute " << form.getName() << " because of " << e.what()
                  << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &a) {
    out << a.getName() << ", bureaucrat grade " << a.getGrade();
    return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }
