#pragma once

#include "AForm.h"
#include <iostream>
#include <stdint.h>

class ShrubberyCreationForm : public AForm {
  private:
    std::string _target;

  public:
    ShrubberyCreationForm(const std::string &target = "Untargeted");
    ShrubberyCreationForm(const ShrubberyCreationForm &a);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &a);
    virtual ~ShrubberyCreationForm();
    void                   execute(const Bureaucrat &executor) const;
    void                   printAsciiTree() const;
};
