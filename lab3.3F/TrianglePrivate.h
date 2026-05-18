#pragma once
#include "Point.h"

class TrianglePrivate : private Point {
private:
    Point A, B, C;

public:
    void Init(Point a, Point b, Point c);

    double perimeter() const;
    double area() const;

    void Display() const;
};
