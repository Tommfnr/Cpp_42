#include "Zombie.hpp"


int main()
{
    std::cout << "\n=== Test 10 zombieHorde ===" << std::endl;
    int N = 10;
    Zombie* horde1 = zombieHorde(N, "Prout");
    for (int i = 0; i < N; i++){   
        horde1[i].announce();
    }
    delete[] horde1;

    std::cout << "\n=== Test 2 zombieHorde ===" << std::endl;
    N -= 8;
    Zombie* horde2 = zombieHorde(N, "Prout");
    for (int i = 0; i < N; i++){   
        horde2[i].announce();
    }
    delete[] horde2;

    std::cout << "\n=== Test 1000 zombieHorde ===" << std::endl;
    N += 998;
    Zombie* horde3 = zombieHorde(N, "Prout");
    for (int i = 0; i < N; i++){   
        horde3[i].announce();
    }
    delete[] horde3;

    std::cout << "\n=== Fin des tests ===" << std::endl;
    return 0;
}


