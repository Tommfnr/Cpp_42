#include "iter.hpp"
#include <iostream>

// Fonction qui modifie l'element (non-const reference)
template <typename T>
void increment(T &arg) {
    arg++;
}

// Fonction qui lit l'element (const reference)
template <typename T>
void print(T const &arg) {
    std::cout << arg << " ";
}

int main(void)
{
    // Test 1: tableau d'int, modification (non-const reference)
    int intArr[] = {1, 2, 3, 4, 5};

    std::cout << "int avant : ";
    iter(intArr, 5, print<int>);
    std::cout << std::endl;

    iter(intArr, 5, increment<int>);

    std::cout << "int apres : ";
    iter(intArr, 5, print<int>);
    std::cout << std::endl;

    // Test 2: tableau de char, modification (non-const reference)
    char charArr[] = {'a', 'b', 'c'};

    std::cout << "char avant : ";
    iter(charArr, 3, print<char>);
    std::cout << std::endl;

    iter(charArr, 3, increment<char>);

    std::cout << "char apres : ";
    iter(charArr, 3, print<char>);
    std::cout << std::endl;

    // Test 3: tableau const, lecture seule (const reference)
    const int constArr[] = {10, 20, 30};

    std::cout << "const int : ";
    iter(constArr, 3, print<int>);
    std::cout << std::endl;

    return 0;
}
