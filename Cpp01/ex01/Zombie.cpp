#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name): _name (name) {}
Zombie::Zombie( void ) {}

Zombie::~Zombie(){
    std::cout << this->_name << ": is destroy!" << std::endl;
}

void Zombie::Setname(std::string name){
    _name = name;
}

void Zombie::announce() const {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
