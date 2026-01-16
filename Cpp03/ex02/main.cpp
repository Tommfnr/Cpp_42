#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "===== CLAPTRAP =====" << std::endl;
    ClapTrap a("Jack");
    a.attack("Enemy");

    std::cout << "\n===== SCAVTRAP =====" << std::endl;
    ScavTrap b("Guardian");
    b.attack("Intruder");
    b.guardGate();

    std::cout << "\n===== FRAGTRAP =====" << std::endl;
    FragTrap c("soldat");
    c.attack("Nazi");
    c.highFivesGuys();

    std::cout << "\n===== END SCOPE =====" << std::endl;
    return 0;
}
