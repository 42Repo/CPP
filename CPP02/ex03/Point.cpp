#include "Point.h"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &p) : _x(p._x), _y(p._y) {}

Point &Point::operator=(const Point &p) {
    (void)p;
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const { return _x; }

Fixed Point::getY() const { return _y; }
