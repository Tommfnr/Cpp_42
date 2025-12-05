#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>

class HumanA
{
    private:

        std::string _Weapon;
        std::string _name;

    public:

        HumanA(std::string _Weapon, std::string _name);
        void attack(void) const;
};


#endif