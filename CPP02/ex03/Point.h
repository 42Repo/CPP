#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point {
  public:
    Point();
    Point(const float x, const float y);
    Point(const Point &p);
    Point &operator=(const Point &p);
    ~Point();

    Fixed getX() const;
    Fixed getY() const;

  private:
    const Fixed _x;
    const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif // POINT_H
