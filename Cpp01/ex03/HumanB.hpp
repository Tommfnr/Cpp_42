#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    private:

        Weapon _Weapon;
        std::string _name;

    public:

        HumanB(std::string name);
        void setWeapon(Weapon weapon);
        void attack(void) const;
};


#endif