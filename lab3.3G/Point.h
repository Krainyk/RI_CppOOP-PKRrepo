#pragma once
#include "Object.h"
#include <iostream>
#include <cmath>
using namespace std;

class Point : public Object {
private:
    double x, y;

public:
    Point(double x0 = 0, double y0 = 0);

    void setX(double x0);
    void setY(double y0);

    double getX() const;
    double getY() const;

    void moveX(double dx);
    void moveY(double dy);

    double distanceToOrigin() const;
    double distanceTo(const Point& p) const;

    void toPolar() const;

    bool equals(const Point& p) const;

    void Display() const;
};