/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:24:22 by asuc              #+#    #+#             */
/*   Updated: 2024/07/06 23:14:43 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(Fixed const &f) {
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed &Fixed::operator=(Fixed const &f) {
    std::cout << "Assignation operator called" << std::endl;
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
