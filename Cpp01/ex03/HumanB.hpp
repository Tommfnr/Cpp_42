#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

class HumanB
{
    private:

        std::string _Weapon;
        std::string _name;

    public:

        HumanB(std::string _Weapon, std::string _name);
        void attack(void) const;
};


#endif