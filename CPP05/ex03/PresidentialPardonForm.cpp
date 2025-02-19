#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon", 25, 5),
      _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a)
    : AForm("Presidential Pardon", 25, 5),
      _target(a._target) {
    *this = a;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &a) {
    if (this != &a) {
        AForm::operator=(a);
        _target = a._target;
    }
    return *this;
}

void PresidentialPardonForm::beExecuted() const {
    std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
