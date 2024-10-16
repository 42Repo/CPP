#include "Fixed.h"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(Fixed const &f) { *this = f; }

Fixed &Fixed::operator=(Fixed const &f) {
    _value = f.getRawBits();
    return *this;
}

Fixed::Fixed(const int value) { _value = value << _fractionalBits; }

Fixed::Fixed(const float value) {
    if (std::fabs(value) < (1.0f / (1 << _fractionalBits))) {
        _value = 0;
    } else {
        _value = static_cast<int>(roundf(value * (1 << _fractionalBits)));
    }
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const { return _value; }

void Fixed::setRawBits(int const raw) { _value = raw; }

float Fixed::toFloat() const { return static_cast<float>(_value) / (1 << _fractionalBits); }

int Fixed::toInt() const { return _value >> _fractionalBits; }

bool Fixed::operator>(Fixed const &f1) const { return _value > f1._value; }

bool Fixed::operator<(Fixed const &f1) const { return _value < f1._value; }

bool Fixed::operator>=(Fixed const &f1) const { return _value >= f1._value; }

bool Fixed::operator<=(Fixed const &f1) const { return _value <= f1._value; }

bool Fixed::operator==(Fixed const &f1) const { return _value == f1._value; }

bool Fixed::operator!=(Fixed const &f1) const { return _value != f1._value; }

Fixed Fixed::operator+(Fixed const &f1) const {
    Fixed result;
    result._value = this->_value + f1._value;
    return result;
}

Fixed Fixed::operator-(Fixed const &f1) const {
    Fixed result;
    result._value = this->_value - f1._value;
    return result;
}

Fixed Fixed::operator*(Fixed const &f1) const {
    Fixed result;
    long  temp = static_cast<long>(this->_value) * static_cast<long>(f1._value);
    result._value = static_cast<int>(temp >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(Fixed const &f1) const {
    if (f1._value == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    Fixed result;
    long temp = (static_cast<long>(this->_value) << _fractionalBits) / static_cast<long>(f1._value);
    result._value = static_cast<int>(temp);
    return result;
}

// Increment/Decrement Operators
Fixed &Fixed::operator++() {
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++_value;
    return temp;
}

Fixed &Fixed::operator--() {
    --_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --_value;
    return temp;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
    if (f1 < f2)
        return f1;
    return f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
    if (f1 < f2)
        return f1;
    return f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
    if (f1 > f2)
        return f1;
    return f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
    if (f1 > f2)
        return f1;
    return f2;
}

std::ostream &operator<<(std::ostream &out, Fixed const &f) {
    out << f.toFloat();
    return out;
}
