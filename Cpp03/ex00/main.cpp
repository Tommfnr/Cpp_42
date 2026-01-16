#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "========== CONSTRUCTORS ==========" << std::endl;
    ClapTrap a("Jack");
    ClapTrap b("Enemy");

    std::cout << "\n========== BASIC ACTIONS ==========" << std::endl;
    a.attack("Enemy");
    b.takeDamage(0);
    a.beRepaired(5);

    std::cout << "\n========== ENERGY DEPLETION ==========" << std::endl;
    for (int i = 0; i < 11; i++)
        a.attack("Enemy");

    std::cout << "\n========== REPAIR WITHOUT ENERGY ==========" << std::endl;
    a.beRepaired(5);

    std::cout << "\n========== DAMAGE & DEATH ==========" << std::endl;
    b.takeDamage(3);
    b.takeDamage(4);
    b.takeDamage(10); // doit tomber à 0

    std::cout << "\n========== ACTIONS WHEN DEAD ==========" << std::endl;
    b.attack("Jack");
    b.beRepaired(5);

    std::cout << "\n========== COPY CONSTRUCTOR ==========" << std::endl;
    ClapTrap c(a);

    std::cout << "\n========== COPY ASSIGNMENT ==========" << std::endl;
    ClapTrap d;
    d = b;

    std::cout << "\n========== SCOPE END ==========" << std::endl;
    return 0;
}

