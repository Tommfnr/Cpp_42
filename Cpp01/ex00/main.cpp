#include "Zombie.hpp"

// Déclaration des fonctions externes
Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    std::cout << "=== Test création sur le tas ===" << std::endl;
    Zombie* zombie1 = newZombie("HeapOne");
    Zombie* zombie2 = newZombie("HeapTwo");

    zombie1->announce();
    zombie2->announce();

    std::cout << "Suppression des zombies du tas..." << std::endl;
    delete zombie1; // destructeur appelé
    delete zombie2;

    std::cout << "\n=== Test création sur la pile ===" << std::endl;
    Zombie stackZombie1("StackOne");
    Zombie stackZombie2("StackTwo");

    stackZombie1.announce();
    stackZombie2.announce();
    // Pas besoin de delete, destructeur automatique à la fin du scope

    std::cout << "\n=== Test randomChump ===" << std::endl;
    randomChump("RandomOne");
    randomChump("RandomTwo");
    // Les zombies sont détruits à la fin de la fonction

    std::cout << "\n=== Test mélange heap et pile ===" << std::endl;
    Zombie stackZombie3("StackThree");
    Zombie* heapZombie3 = newZombie("HeapThree");

    stackZombie3.announce();
    heapZombie3->announce();

    std::cout << "Suppression du zombie du tas..." << std::endl;
    delete heapZombie3;

    std::cout << "\n=== Fin des tests ===" << std::endl;

    return 0;
}

