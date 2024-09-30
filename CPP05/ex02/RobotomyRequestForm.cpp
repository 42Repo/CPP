#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", 72, 45),
      _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a)
    : AForm("Robotomy Request", 72, 45),
      _target(a._target) {
    *this = a;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &a) {
    if (this != &a) {
        AForm::operator=(a);
        _target = a._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
