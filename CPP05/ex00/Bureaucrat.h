#pragma once

#include <iostream>
#include <stdint.h>

const int16_t MAX_GRADE = 1;
const int16_t MIN_GRADE = 150;

class Bureaucrat {
  private:
    const std::string _name;
    int16_t           _grade;

  public:
    Bureaucrat();
    Bureaucrat(std::string name, int16_t grade);
    Bureaucrat(const Bureaucrat &a);
    ~Bureaucrat();
    std::string getName() const;
    int16_t     getGrade() const;
    void        incrementGrade();
    void        decrementGrade();

    class GradeTooHighException : public std::exception {
      public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &a);
