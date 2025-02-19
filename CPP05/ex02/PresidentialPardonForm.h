#pragma once

#include "AForm.h"

class PresidentialPardonForm : public AForm {
  private:
    PresidentialPardonForm();
    
    std::string _target;
    void        beExecuted() const;

  public:
    PresidentialPardonForm(const std::string &target = "Untargeted");
    PresidentialPardonForm(const PresidentialPardonForm &a);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &a);
    virtual ~PresidentialPardonForm();
};
