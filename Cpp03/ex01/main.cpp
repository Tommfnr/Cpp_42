#include "ScavTrap.hpp"
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

    std::cout << "\n===== END SCOPE =====" << std::endl;
    return 0;
}
