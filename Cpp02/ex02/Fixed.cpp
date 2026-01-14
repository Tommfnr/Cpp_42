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

bool Fixed::operator>(const Fixed& other) const {
    return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_rawBits != other._rawBits;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_rawBits + other._rawBits);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_rawBits - other._rawBits);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long tmp = (long)this->_rawBits * (long)other._rawBits;
    result.setRawBits(tmp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    long tmp = ((long)this->_rawBits << _fractionalBits) / other._rawBits;
    result.setRawBits(tmp);
    return result;
}

Fixed& Fixed::operator++() {
    this->_rawBits++;
    return *this;
}

Fixed& Fixed::operator--() {
    this->_rawBits--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_rawBits++;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_rawBits--;
    return temp;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
    return (f1 < f2 ? f1 : f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
    return (f1 < f2 ? f1 : f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
    return (f1 > f2 ? f1 : f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
    return (f1 > f2 ? f1 : f2);
}
