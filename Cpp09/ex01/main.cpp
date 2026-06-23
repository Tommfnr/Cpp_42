#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2){
        std::cerr << "Error: usage: ./RPN <expression>\n"; 
        return (1);
    }

    try{
        RPN stack;
        stack.proceed(av[1]);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}