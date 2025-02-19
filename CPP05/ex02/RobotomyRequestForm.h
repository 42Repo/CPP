#pragma once

#include "AForm.h"
#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm : public AForm {
  private:
    RobotomyRequestForm();
    
    std::string _target;
    void        beExecuted() const;

  public:
    RobotomyRequestForm(const std::string &target = "Untargeted");
    RobotomyRequestForm(const RobotomyRequestForm &a);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &a);
    virtual ~RobotomyRequestForm();
};
