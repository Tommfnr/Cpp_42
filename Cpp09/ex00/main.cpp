#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2){
        std::cout << "Error: usage: ./btc <file_name>\n"; 
        return (1);
    }

    try{
        BitcoinExchange btc;
        btc.processInputFile(av[1]);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return (1);
    }
    return (0);
}