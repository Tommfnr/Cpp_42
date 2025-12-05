#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name ){

    Zombie *buff;
    buff = new Zombie[N];
    
    for (int i = 0; i < N; i++){   
        buff[i].Setname(name);
    }
    return (buff);
}