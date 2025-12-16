#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : _Weapon(NULL), _name(name)
{}

void HumanB::setWeapon(Weapon &weapon) {
    _Weapon = &weapon;
}

void HumanB::attack() const{
    if (_Weapon->getType() == ""){
        std::cout << _name << " attacks with their hand"<< std::endl;
        return ;
    }
    std::cout << _name << " attacks with their " << _Weapon->getType() << std::endl;
}