#include "ScalarConverter.h"

void ScalarConverter::convert(std::string const &input) {
    try {
        double d = strtod(input.c_str(), NULL);
        if (d >= 0 && d <= 127 && std::isprint(static_cast<char>(d)) && std::floor(d) == d) {
            char c = static_cast<char>(d);
            std::cout << "char: '" << c << "'" << std::endl;
        } else {
            throw std::invalid_argument("Non-displayable or impossible char");
        }
    } catch (...) {
        std::cerr << "char: impossible" << std::endl;
    }

    try {
        char  *end;
        double i = std::strtod(input.c_str(), &end);
        if (i >= std::numeric_limits<int>::min() && i <= std::numeric_limits<int>::max() &&
            std::floor(i) == i && ((*end == 'f' && *(end + 1) == '\0') || *end == '\0')) {
            std::cout << "int: " << static_cast<int>(i) << std::endl;
        } else {
            throw std::invalid_argument("Impossible conversion");
        }
    } catch (...) {
        std::cout << "int: impossible" << std::endl;
    }

    try {
        char  *end;
        double f = std::strtod(input.c_str(), &end);

        if ((*end == 'f' && *(end + 1) == '\0') || *end == '\0') {
            if (f == std::numeric_limits<float>::infinity()) {
                std::cout << "float: +inff" << std::endl;
            } else if (f == -std::numeric_limits<float>::infinity()) {
                std::cout << "float: -inff" << std::endl;
            } else if (std::isnan(f)) {
                std::cout << "float: nanf" << std::endl;
            } else {
                std::cout << "float: " << f << "f" << std::endl;
            }
        } else {
            throw std::invalid_argument("Impossible conversion");
        }
    } catch (...) {
        std::cout << "float: impossible" << std::endl;
    }

    try {
        char  *end;
        double d = std::strtod(input.c_str(), &end);
        if ((*end == 'f' && *(end + 1) == '\0') || *end == '\0') {
            if (d == std::numeric_limits<double>::infinity()) {
                std::cout << "double: +inf" << std::endl;
            } else if (d == -std::numeric_limits<double>::infinity()) {
                std::cout << "double: -inf" << std::endl;
            } else if (std::isnan(d)) {
                std::cout << "double: nan" << std::endl;
            } else {
                std::cout << "double: " << d << std::endl;
            }
        } else {
            throw std::invalid_argument("Impossible conversion");
        }
    } catch (...) {
        std::cout << "double: impossible" << std::endl;
    }
}
