#pragma once
#include "Point.h"

class TrianglePublic : public Point {
private:
    Point A, B, C;

public:
    void Init(Point a, Point b, Point c);

    double sideAB() const;
    double sideBC() const;
    double sideCA() const;

    double perimeter() const;
    double area() const;

    void Display() const;
};