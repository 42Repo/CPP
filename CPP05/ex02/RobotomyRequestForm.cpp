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

void RobotomyRequestForm::beExecuted() const {
    std::cout << "Bzzzzz Bzzzzz Bzzzzz" << std::endl;
    std::srand(static_cast<unsigned int>(time(0)));
    if (std::rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomization of " << _target << " has failed." << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm() {}
