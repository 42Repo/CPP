#include "BitcoinExchange.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &dbFile) { _loadDatabase(dbFile); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : exchangeRates(other.exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

void BitcoinExchange::_loadDatabase(const std::string &dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string        date;
        double             rate = 0;
        if (std::getline(iss, date, ',') && iss >> rate) {
            exchangeRates[date] = rate;
        }
    }
}

double BitcoinExchange::getValueOnDate(const std::string &date, double value) const {
    std::map<std::string, double>::const_iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.end() || it->first != date) {
        if (it == exchangeRates.begin()) {
            throw std::runtime_error("Error: date not found.");
        }
        --it;
    }
    return it->second * value;
}

void BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.size() != 11 || date[4] != '-' || date[7] != '-') {
        throw std::runtime_error("Error: bad date format.");
    }
    int                year = 0;
    int                month = 0;
    int                day = 0;
    char               dash1 = 0;
    char               dash2 = 0;
    std::istringstream dateStream(date);

    dateStream >> year >> dash1 >> month >> dash2 >> day;
    if (dash1 != '-' || dash2 != '-' || month < 1 || month > 12 || day < 1 || day > 31) {
        throw std::runtime_error("Error: bad date format.");
    }
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((day > 29) || (!isLeapYear && day > 28)) {
            throw std::runtime_error("Error: bad date format.");
        }
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        throw std::runtime_error("Error: bad date format.");
    }
}

void BitcoinExchange::isValidValue(double value) const {
    if (value < 0) {
        throw std::runtime_error("Error: negative value.");
    }
    if (value > 1000) {
        throw std::runtime_error("Error: value too high.");
    }
}
