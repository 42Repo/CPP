#include "BitcoinExchange.h"
#include <fstream>
#include <iostream>
#include <sstream>

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
            double             value = 0;
            if (std::getline(iss, date, '|') && iss >> value) {
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
