#include "ScalarConverter.h"
#include <cerrno>
#include <cfloat>
#include <climits>
#include <cmath>
#include <iomanip>

void ScalarConverter::convert(std::string const &input) {
    char *endptr = NULL;
    errno = 0;
    double d = std::strtod(input.c_str(), &endptr);

    if (errno != 0 || (*endptr != '\0' && *endptr != 'f') ||
        (*endptr == 'f' && *(endptr + 1) != '\0')) {
        std::cout << "char: impossible" << '\n';
        std::cout << "int: impossible" << '\n';
        std::cout << "float: impossible" << '\n';
        std::cout << "double: impossible" << '\n';
        return;
    }

    if (input.length() == 1 && (std::isprint(input[0]) != 0)) {
        std::cout << "char: '" << input[0] << "'" << '\n';
        std::cout << "int: " << static_cast<int>(input[0]) << '\n';
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(input[0])
                  << "f" << '\n';
        std::cout << "double: " << std::fixed << std::setprecision(1)
                  << static_cast<double>(input[0]) << '\n';
        return;
    }

    if (d >= 0 && d <= 127 && std::floor(d) == d) {
        char c = static_cast<char>(d);
        if (std::isprint(c) != 0) {
            std::cout << "char: '" << c << "'" << '\n';
        } else {
            std::cout << "char: Non displayable" << '\n';
        }
    } else {
        std::cout << "char: impossible" << '\n';
    }

    if (d >= INT_MIN && d <= INT_MAX && std::floor(d) == d) {
        std::cout << "int: " << static_cast<int>(d) << '\n';
    } else {
        std::cout << "int: impossible" << '\n';
    }

    float f = static_cast<float>(d);
    if (std::isnan(f)) {
        std::cout << "float: nanf" << '\n';
    } else if (std::isinf(f)) {
        if (f > 0)
            std::cout << "float: +inff" << '\n';
        else
            std::cout << "float: -inff" << '\n';
    } else
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << '\n';

    if (std::isnan(d)) {
        std::cout << "double: nan" << '\n';
    } else if (std::isinf(d)) {
        if (d > 0)
            std::cout << "double: +inf" << '\n';
        else
            std::cout << "double: -inf" << '\n';
    } else
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << '\n';
}
