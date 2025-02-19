#pragma once

#include "AForm.h"
#include <fstream>

class ShrubberyCreationForm : public AForm {
  private:
    ShrubberyCreationForm();

    std::string _target;
    void        beExecuted() const;

  public:
    ShrubberyCreationForm(const std::string &target = "Untargeted");
    ShrubberyCreationForm(const ShrubberyCreationForm &a);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &a);
    virtual ~ShrubberyCreationForm();
};
