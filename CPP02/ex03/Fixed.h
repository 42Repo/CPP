#ifndef FIXED_H
#define FIXED_H

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

    int   getRawBits() const;
    void  setRawBits(const int raw);
    float toFloat() const;
    int   toInt() const;

    // Comparison operators
    bool operator>(Fixed const &f1) const;
    bool operator<(Fixed const &f1) const;
    bool operator>=(Fixed const &f1) const;
    bool operator<=(Fixed const &f1) const;
    bool operator==(Fixed const &f1) const;
    bool operator!=(Fixed const &f1) const;

    // Arithmetic operators
    Fixed operator+(Fixed const &f1) const;
    Fixed operator-(Fixed const &f1) const;
    Fixed operator*(Fixed const &f1) const;
    Fixed operator/(Fixed const &f1) const;

    // Increment/Decrement operators
    Fixed &operator++();    // Pre-increment
    Fixed  operator++(int); // Post-increment
    Fixed &operator--();    // Pre-decrement
    Fixed  operator--(int); // Post-decrement

    // Min/Max functions
    static const Fixed &min(const Fixed &f1, const Fixed &f2);
    static Fixed       &min(Fixed &f1, Fixed &f2);
    static const Fixed &max(const Fixed &f1, const Fixed &f2);
    static Fixed       &max(Fixed &f1, Fixed &f2);

  private:
    int              _value;
    static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &f);

#endif
