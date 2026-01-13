#include "Fixed.hpp"
#include "math.h"

Fixed::Fixed() : _rawBits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;

}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    
}

int Fixed::getRawBits(void) const
{
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
}


Fixed::Fixed(const int nb)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = nb << 8;
}

Fixed::Fixed(const float nb)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(nb* (1 << _fractionalBits));
}

float Fixed::toFloat( void ) const{
    return getRawBits() / 256.0f;
}

int Fixed::toInt( void ) const {
    return getRawBits() >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();
    return os;
}