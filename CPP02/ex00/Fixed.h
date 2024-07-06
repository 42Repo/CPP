/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuc <asuc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:24:09 by asuc              #+#    #+#             */
/*   Updated: 2024/07/06 19:07:57 by asuc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Fixed_H__
#define __Fixed_H__

#include <iostream>

class Fixed {
  public:
    Fixed();
    Fixed(Fixed const &f);
    Fixed &operator=(Fixed const &f);
    ~Fixed();
    int  getRawBits(void) const;
    void setRawBits(int const raw);

  private:
    int              _value;
    static const int _fractionalBits = 8;
};

#endif // __Fixed_H__