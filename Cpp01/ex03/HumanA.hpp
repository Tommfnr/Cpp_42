#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    private:

        Weapon& _Weapon;
        std::string _name;

    public:
    
        HumanA(const std::string &name, Weapon &Weapon);
        void attack(void) const;
};


#endif