#ifndef Fixed_H
#define Fixed_H

#include <cmath>
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

#endif // Fixed_H
