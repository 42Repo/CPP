#pragma once

#include "AForm.h"

class RobotomyRequestForm : public AForm {
  private:
    std::string _target;
    void        beExecuted() const;

  public:
    RobotomyRequestForm(const std::string &target = "Untargeted");
    RobotomyRequestForm(const RobotomyRequestForm &a);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &a);
    virtual ~RobotomyRequestForm();
};
