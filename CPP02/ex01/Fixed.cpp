#include "Fixed.h"

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(Fixed const &f) {
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed &Fixed::operator=(Fixed const &f) {
    std::cout << "Copy assignment operator called" << std::endl;
    _value = f.getRawBits();
    return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float Fixed::toFloat(void) const { return static_cast<float>(_value) / (1 << _fractionalBits); }

int Fixed::toInt(void) const { return _value >> _fractionalBits; }

std::ostream &operator<<(std::ostream &out, Fixed const &f) {
    out << f.toFloat();
    return (out);
}
