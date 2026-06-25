#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: usage: ./PmergeMe <list of numbers>" << std::endl;
        return (1);
    }

    try
    {
        PmergeMe p;
        p.parse(ac, av);
        p.sort();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
