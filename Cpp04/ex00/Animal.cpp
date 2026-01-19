#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        type = other.type;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}


Animal::~Animal()
{
    std::cout << "Destructor called" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "* Animal generic sound *" << std::endl;
}