#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _Hit_p = 100;
    _Energie_p = 50;
    _Attack_p = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _Hit_p = 100;
    _Energie_p = 50;
    _Attack_p = 20;
    std::cout << "ScavTrap " << _name << " constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    ClapTrap::operator=(other);
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_Hit_p <= 0 || _Energie_p <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack." << std::endl;
        return;
    }
    _Energie_p--;
    std::cout << "ScavTrap " << _name << " viciously attacks " << target << ", causing " << _Attack_p << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name
              << " is now in Gate keeper mode." << std::endl;
}
