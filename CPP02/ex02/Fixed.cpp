/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:24:22 by asuc              #+#    #+#             */
/*   Updated: 2024/09/10 22:51:05 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(Fixed const &f) {
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fractionalBits;
    std::cout << value << "  MA BITE " << _value << std::endl << std::endl;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(value * (1 << _fractionalBits));
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

float Fixed::toFloat(void) const { return (float)_value / (1 << _fractionalBits); }

int Fixed::toInt(void) const { return _value >> _fractionalBits; }

std::ostream &operator<<(std::ostream &out, Fixed const &f) {
    out << f.toFloat();
    return (out);
}

bool Fixed::operator>(Fixed const &f1) {
    if (this->toFloat() > f1.toFloat())
        return 1;
    return 0;
}

bool Fixed::operator<(Fixed const &f1) {
    if (this->toFloat() < f1.toFloat())
        return 1;
    return 0;
}

bool Fixed::operator>=(Fixed const &f1) {
    if (this->toFloat() >= f1.toFloat())
        return 1;
    return 0;
}

bool Fixed::operator<=(Fixed const &f1) {
    if (this->toFloat() <= f1.toFloat())
        return 1;
    return 0;
}

bool Fixed::operator==(Fixed const &f1) {
    if (this->toFloat() == f1.toFloat())
        return 1;
    return 0;
}

bool Fixed::operator!=(Fixed const &f1) {
    if (this->toFloat() != f1.toFloat())
        return 1;
    return 0;
}

Fixed Fixed::operator+(Fixed const &f1) { return Fixed(this->toFloat() + f1.toFloat()); }

Fixed Fixed::operator-(Fixed const &f1) { return Fixed(this->toFloat() - f1.toFloat()); }

Fixed Fixed::operator*(Fixed const &f1) { return Fixed(this->toFloat() * f1.toFloat()); }

Fixed Fixed::operator/(Fixed const &f1) { return Fixed(this->toFloat() / f1.toFloat()); }

Fixed &Fixed::operator--(void) {
    --_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --_value;
    return temp;
}

Fixed &Fixed::operator++(void) {
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++_value;
    return temp;
}
