#pragma once

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter {

  private:
    ScalarConverter();

  public:
    static void convert(std::string const &input);
};
