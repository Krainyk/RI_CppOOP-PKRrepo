#include "Point.h"

Point::Point(double x0, double y0) {
    x = x0;
    y = y0;
}

void Point::setX(double x0) { x = x0; }
void Point::setY(double y0) { y = y0; }

double Point::getX() const { return x; }
double Point::getY() const { return y; }

void Point::moveX(double dx) { x += dx; }
void Point::moveY(double dy) { y += dy; }

double Point::distanceToOrigin() const {
    return sqrt(x * x + y * y);
}

double Point::distanceTo(const Point& p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

void Point::toPolar() const {
    double r = distanceToOrigin();
    double phi = atan2(y, x);
    cout << "r = " << r << ", phi = " << phi << endl;
}

bool Point::equals(const Point& p) const {
    return x == p.x && y == p.y;
}

void Point::Display() const {
    cout << "(" << x << ", " << y << ")";
}