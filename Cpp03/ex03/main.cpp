#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "========== BASIC CONSTRUCTION ==========" << std::endl;
    DiamondTrap d("Ruby");

    std::cout << "\n========== ATTACK TEST (ScavTrap attack) ==========" << std::endl;
    d.attack("Enemy");

    std::cout << "\n========== SPECIAL ABILITIES ==========" << std::endl;
    d.guardGate();        // from ScavTrap
    d.highFivesGuys();    // from FragTrap

    std::cout << "\n========== WHO AM I ==========" << std::endl;
    d.whoAmI();

    std::cout << "\n========== ENERGY DEPLETION ==========" << std::endl;
    for (int i = 0; i < 55; i++)
        d.attack("Dummy");

    std::cout << "\n========== ACTIONS WITHOUT ENERGY ==========" << std::endl;
    d.attack("NoEnergyTarget");
    d.beRepaired(10);

    std::cout << "\n========== DAMAGE & DEATH ==========" << std::endl;
    d.takeDamage(30);
    d.takeDamage(50);
    d.takeDamage(100);

    std::cout << "\n========== ACTIONS WHEN DEAD ==========" << std::endl;
    d.attack("Ghost");
    d.beRepaired(5);
    d.guardGate();
    d.highFivesGuys();

    std::cout << "\n========== COPY CONSTRUCTOR ==========" << std::endl;
    DiamondTrap copy(d);
    copy.whoAmI();

    std::cout << "\n========== COPY ASSIGNMENT ==========" << std::endl;
    DiamondTrap assign;
    assign = d;
    assign.whoAmI();

    std::cout << "\n========== POLYMORPHISM TEST ==========" << std::endl;
    ClapTrap* base = new DiamondTrap("Poly");
    base->attack("Target");   // must use ScavTrap attack
    delete base;               // must call all destructors in order

    std::cout << "\n========== END OF SCOPE ==========" << std::endl;
    return 0;
}


