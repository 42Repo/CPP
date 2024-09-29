#include "AForm.h"

AForm::AForm(const std::string &name, int16_t gradeToSign, int16_t gradeToExecute)
    : _name(name),
      _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw GradeTooHighException();
    else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &a)
    : _name(a._name),
      _isSigned(a._isSigned),
      _gradeToSign(a._gradeToSign),
      _gradeToExecute(a._gradeToExecute) {}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _isSigned; }

int16_t AForm::getGradeToSign() const { return _gradeToSign; }

int16_t AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat &a) {
    if (a.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() { return "Grade too high"; }

const char *AForm::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream &operator<<(std::ostream &out, const AForm &a) {
    out << a.getName() << ", AForm grade to sign " << a.getGradeToSign()
        << ", AForm grade to execute " << a.getGradeToExecute() << ", AForm is signed "
        << std::boolalpha << a.getIsSigned();
    return out;
}
