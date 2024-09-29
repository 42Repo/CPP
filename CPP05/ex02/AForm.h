#pragma once

#include "Bureaucrat.h"

class AForm {
  private:
    std::string   _name;
    bool          _isSigned;
    const int16_t _gradeToSign;
    const int16_t _gradeToExecute;

  public:
    AForm(const std::string &name = "DefaultAForm", int16_t gradeToSign = 50,
          int16_t gradeToExecute = 100);
    AForm(const AForm &a);
    AForm &operator=(const AForm &a);
    virtual ~AForm();
    std::string getName() const;
    bool        getIsSigned() const;
    int16_t     getGradeToSign() const;
    int16_t     getGradeToExecute() const;
    void        beSigned(const Bureaucrat &a);

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &a);
