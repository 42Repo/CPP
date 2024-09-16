#ifndef Fixed_H
#define Fixed_H

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

#endif // Fixed_H
