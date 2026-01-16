#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _Hit_p = 100;
    _Energie_p = 100;
    _Attack_p = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _Hit_p = 100;
    _Energie_p = 100;
    _Attack_p = 30;
    std::cout << "FragTrap " << _name << " constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_Hit_p <= 0 || _Energie_p <= 0)
    {
        std::cout << "FragTrap " << _name << " can't attack." << std::endl;
        return;
    }
    _Energie_p--;
    std::cout << "FragTrap " << _name << " explosively attacks " << target << ", causing " << _Attack_p << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " want to do a high-fives, do you want to do a high-fives?" << std::endl;
}
