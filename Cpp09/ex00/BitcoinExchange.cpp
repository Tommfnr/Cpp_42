#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

static bool isValidDate(const std::string& date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    struct tm t = {};
    t.tm_year = std::atoi(date.substr(0, 4).c_str()) - 1900;
    t.tm_mon  = std::atoi(date.substr(5, 2).c_str()) - 1;
    t.tm_mday = std::atoi(date.substr(8, 2).c_str());

    int day   = t.tm_mday;
    int month = t.tm_mon;
    int year  = t.tm_year;

    mktime(&t);

    return (t.tm_mday == day && t.tm_mon == month && t.tm_year == year);
}

static bool isValidValue(const std::string& str) {
    size_t i = str.find_first_not_of(' ');
    if (i == std::string::npos)
        return false;
    if (str[i] == '-')
        i++;
    bool hasDigit = false;
    bool hasDot = false;
    while (i < str.size()) {
        if (std::isdigit(str[i]))
            hasDigit = true;
        else if (str[i] == '.' && !hasDot)
            hasDot = true;
        else
            return false;
        i++;
    }
    return hasDigit;
}

BitcoinExchange::BitcoinExchange() {
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t separator = line.find(',');
        std::string date = line.substr(0, separator);
        float price = std::atof(line.substr(separator + 1).c_str());
        _data[date] = price;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->_data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value")
        throw std::runtime_error("Error: wrong header");

    while (std::getline(inputFile, line))
    {
        size_t separator = line.find('|');
        if (separator == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, separator - 1);
        std::string valueStr = line.substr(separator + 1);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!isValidValue(valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float amount = std::atof(valueStr.c_str());
        if (amount < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (amount > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _data.lower_bound(date);
        if (it == _data.end() || it->first != date) {
            if (it == _data.begin()) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            --it;
        }
        std::cout << date << " => " << amount << " = "
            << std::fixed << std::setprecision(2)
            << static_cast<double>(it->second * amount) << std::endl;
    }
}
