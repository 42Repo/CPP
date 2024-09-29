#include "Form.h"

Form::Form(const std::string &name, int16_t gradeToSign, int16_t gradeToExecute)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw GradeTooHighException();
    else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw GradeTooLowException();
}

Form::Form(const Form &a)
    : _name(a._name),
      _isSigned(a._isSigned),
      _gradeToSign(a._gradeToSign),
      _gradeToExecute(a._gradeToExecute) {}

Form::~Form() {}

std::string Form::getName() const { return _name; }

bool Form::getIsSigned() const { return _isSigned; }

int16_t Form::getGradeToSign() const { return _gradeToSign; }

int16_t Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &a) {
    if (a.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char *Form::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream &operator<<(std::ostream &out, const Form &a) {
    out << a.getName() << ", form grade to sign " << a.getGradeToSign()
        << ", form grade to execute " << a.getGradeToExecute() << ", form is signed "
        << std::boolalpha << a.getIsSigned();
    return out;
}
