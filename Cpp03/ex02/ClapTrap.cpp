#include "ClapTrap.hpp"
#include <iostream>


ClapTrap::ClapTrap()
{
    _name = "Hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm";
    _Hit_p = 10;
    _Energie_p = 10;
    _Attack_p = 0;
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _Hit_p = other._Hit_p;
        _Energie_p = other._Energie_p;
        _Attack_p = other._Attack_p;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}


ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _Hit_p(10), _Energie_p(10), _Attack_p(0)
{
    std::cout << "ClapTrap " << _name << " constructed" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if (_Hit_p <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't attack." << std::endl;
        return;
    }
    if (_Energie_p <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy left." << std::endl;
        return;
    }
    _Energie_p--;
    std::cout << "ClapTrap " << _name << " attacks " <<  target << ", causing " << _Attack_p << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_Hit_p <= 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
        return;
    }

    if (amount >= static_cast<unsigned int>(_Hit_p))
        _Hit_p = 0;
    else
        _Hit_p -= amount;

    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " points of damage! (HP: " << _Hit_p << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_Hit_p <= 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and can't be repaired." << std::endl;
        return;
    }
    if (_Energie_p <= 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy left." << std::endl;
        return;
    }

    _Energie_p--;
    _Hit_p += amount;

    std::cout << "ClapTrap " << _name
              << " repairs itself for " << amount
              << " hit points! (HP: " << _Hit_p << ")" << std::endl;
}


