#pragma once

#include "Bureaucrat.h"

class Form {
  private:
    std::string   _name;
    bool          _isSigned;
    const int16_t _gradeToSign;
    const int16_t _gradeToExecute;

  public:
    Form(const std::string &name = "DefaultForm", int16_t gradeToSign = 50,
         int16_t gradeToExecute = 100);
    Form(const Form &a);
    Form &operator=(const Form &a);
    ~Form();
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

std::ostream &operator<<(std::ostream &out, const Form &a);
