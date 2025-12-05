#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : _Weapon(NULL), _name(name)
{}

void HumanB::setWeapon(Weapon weapon) {
    weapon.setType(weapon.getType());
}

void HumanB::attack() const{
    std::cout << _name << " attacks with their " << _Weapon.getType() << std::endl;
}