#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

static std::string stripWhitespace(const std::string &str) {
    std::string result;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (isspace(*it) == 0) {
            result += *it;
        }
    }
    return result;
}

static bool isValidNumber(const std::string &str) {
    if (str.empty())
        return false;

    std::string stripped = stripWhitespace(str);
    for (size_t i = 0; i < stripped.length(); ++i) {
        if (isdigit(stripped[i]) == 0 && stripped[i] != '.')
            return false;
    }

    std::istringstream iss(stripped);
    double             value = 0;
    return (iss >> value) && iss.eof();
}

static double stringToDouble(const std::string &str) {
    std::istringstream iss(str);
    double             value = 0;
    iss >> value;
    return value;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    BitcoinExchange exchange("data.csv");
    std::string     line;

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string        date;
        std::string        valueStr;

        if (!std::getline(iss, date, '|') || !std::getline(iss, valueStr)) {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }

        date = stripWhitespace(date);
        valueStr = stripWhitespace(valueStr);

        if (!isValidNumber(valueStr)) {
            std::cerr << "Error: not a valid number.\n";
            continue;
        }

        double value = stringToDouble(valueStr);

        try {
            exchange.isValidDate(date);
            exchange.isValidValue(value);
            double result = exchange.getValueOnDate(date, value);
            std::cout << date << " => " << value << " = " << result << "\n";
        } catch (const std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }
    return 0;
}
