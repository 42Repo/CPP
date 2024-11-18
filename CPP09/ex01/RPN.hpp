#pragma once

#include <string>

class RPN {
  public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();
    int evaluate(const std::string &expression);
};
