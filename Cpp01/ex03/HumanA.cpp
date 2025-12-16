#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon)
    : _Weapon(weapon), _name(name)
{}


void HumanA::attack(void) const{
    std::cout << _name << " attacks with their " << _Weapon.getType() << std::endl;
}