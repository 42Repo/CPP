#include "Point.h"

static Fixed area(Point const a, Point const b, Point const c) {
    return Fixed(std::abs((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())) +
                          (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())) +
                          (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) /
                 2.0f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = area(a, b, c);
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);

    return (area1 + area2 + area3) == totalArea;
}
