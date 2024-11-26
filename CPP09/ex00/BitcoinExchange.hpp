#pragma once

#include <map>
#include <string>

class BitcoinExchange {
  public:
    explicit BitcoinExchange(const std::string &dbFile);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    double           getValueOnDate(const std::string &date, double value) const;
    void             isValidDate(const std::string &date) const;
    void             isValidValue(double value) const;

  private:
    BitcoinExchange();
    std::map<std::string, double> exchangeRates;
    void                          _loadDatabase(const std::string &dbFile);
};
