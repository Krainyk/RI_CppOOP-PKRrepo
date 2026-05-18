#include "Point.h"

void Point::Init(double x0, double y0) {
    x = x0;
    y = y0;
}

double Point::distanceTo(const Point& p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

void Point::Display() const {
    cout << "(" << x << ", " << y << ")";
}