#include "BitcoinExchange.h"
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
    std::istringstream iss(str);
    double             number = 0;
    char               charVal = '\0';

    std::string strTemp = stripWhitespace(str);
    for (std::string::const_iterator it = strTemp.begin(); it != strTemp.end(); ++it) {
        if (isdigit(*it) == 0 && *it != '.') {
            return false;
        }
    }
    return (iss >> number) && !(iss >> charVal);
}

static double stringToDouble(const std::string &str) {
    std::istringstream iss(str);
    double             value = 0;
    iss >> value;
    return value;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange("data.csv");
        std::ifstream   inputFile(argv[1]);
        if (!inputFile.is_open()) {
            throw std::runtime_error("Error: could not open file.");
        }

        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string        date;
            std::string        valueStr;
            double             value = 0;
            if (std::getline(iss, date, '|') && std::getline(iss, valueStr) &&
                isValidNumber(valueStr)) {
                date = stripWhitespace(date);
                value = stringToDouble(valueStr);
                try {
                    exchange.isValidDate(date);
                    exchange.isValidValue(value);
                } catch (const std::exception &e) {
                    std::cerr << e.what() << std::endl;
                    continue;
                }
                double result = exchange.getValueOnDate(date, value);
                std::cout << date << " => " << value << " = " << result << std::endl;
            } else {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
