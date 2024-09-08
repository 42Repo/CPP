/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:24:09 by asuc              #+#    #+#             */
/*   Updated: 2024/09/08 22:37:59 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Fixed_H__
#define __Fixed_H__

#include <iostream>

class Fixed {
  public:
    Fixed();
    Fixed(const Fixed &f);
    Fixed &operator=(Fixed const &f);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();
    int   getRawBits(void) const;
    void  setRawBits(const int raw);
    float toFloat(void) const;
    int   toInt(void) const;

  private:
    int              _value;
    static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &f);

#endif // __Fixed_H__