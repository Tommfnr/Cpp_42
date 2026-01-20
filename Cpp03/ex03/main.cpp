#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Création de DiamondTrap dt1 ===" << std::endl;
    DiamondTrap dt1("DiamondOne");

    std::cout << "\n=== Test des stats et attack ===" << std::endl;
    dt1.attack("Target1");       // doit utiliser ScavTrap::attack
    dt1.takeDamage(20);          // prend des dégâts
    dt1.beRepaired(15);          // se soigne
    dt1.highFivesGuys();         // méthode FragTrap
    dt1.whoAmI();                // affiche son nom et celui du ClapTrap

    std::cout << "\n=== Test du constructeur par copie ===" << std::endl;
    DiamondTrap dt2(dt1);
    dt2.whoAmI();
    dt2.attack("Target2");

    std::cout << "\n=== Test de l'opérateur d'assignation ===" << std::endl;
    DiamondTrap dt3;
    dt3 = dt1;
    dt3.whoAmI();
    dt3.takeDamage(50);
    dt3.beRepaired(30);

    std::cout << "\n=== Test du destructeur ===" << std::endl;

    return 0;
}
