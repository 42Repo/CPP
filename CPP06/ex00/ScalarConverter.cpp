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

    if (input.length() == 1 && (std::isprint(input[0]) != 0)) {
        std::cout << "char: '" << input[0] << "'" << '\n';
        d = static_cast<double>(input[0]);
        std::cout << "int: " << static_cast<int>(d) << '\n';
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f"
                  << '\n';
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << '\n';
        return;
    }

    if (errno == 0 && *endptr == '\0' && d >= 0 && d <= 127) {
        if (std::floor(d) == d) {
            if (std::isprint(static_cast<char>(d)) != 0) {
                std::cout << "char: '" << static_cast<char>(d) << "'" << '\n';
            } else {
                std::cout << "char: Non displayable" << '\n';
            }
        } else {
            std::cout << "char: impossible" << '\n';
        }

    } else {
        std::cout << "char: impossible" << '\n';
    }

    if (errno == 0 && (*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0')) &&
        d >= INT_MIN && d <= INT_MAX) {
        if (std::floor(d) == d)
            std::cout << "int: " << static_cast<int>(d) << '\n';
        else
            std::cout << "int: impossible" << '\n';
    } else {
        std::cout << "int: impossible" << '\n';
    }

    if (errno == 0 && (*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0'))) {
        float f = static_cast<float>(d);
        if (std::isnan(f)) {
            std::cout << "float: nanf" << '\n';
        } else if (std::isinf(f) && f > 0) {
            std::cout << "float: +inff" << '\n';
        } else if (std::isinf(f) && f < 0) {
            std::cout << "float: -inff" << '\n';
        } else
            std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << '\n';
    } else {
        std::cout << "float: impossible" << '\n';
    }

    if (errno == 0 && (*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0'))) {
        if (std::isnan(d)) {
            std::cout << "double: nan" << '\n';
        } else if (std::isinf(d) && d > 0) {
            std::cout << "double: +inf" << '\n';
        } else if (std::isinf(d) && d < 0) {
            std::cout << "double: -inf" << '\n';
        } else
            std::cout << "double: " << std::fixed << std::setprecision(1) << d << '\n';
    } else {
        std::cout << "double: impossible" << '\n';
    }
}
