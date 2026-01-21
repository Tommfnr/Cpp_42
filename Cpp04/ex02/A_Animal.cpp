#include "A_Animal.hpp"

A_Animal::A_Animal()
{
    std::cout << "Default constructor called" << std::endl;
}

A_Animal::A_Animal(const A_Animal& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

A_Animal& A_Animal::operator=(const A_Animal& other)
{
    if (this != &other)
    {
        type = other.type;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}


A_Animal::~A_Animal()
{
    std::cout << "Destructor called" << std::endl;
}

std::string A_Animal::getType() const {
    return type;
}

void A_Animal::makeSound() const {
    std::cout << "* A_Animal generic sound *" << std::endl;
}