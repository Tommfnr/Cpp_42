#pragma once

#include <map>
#include <iostream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void processInputFile(const std::string& filename);

};
