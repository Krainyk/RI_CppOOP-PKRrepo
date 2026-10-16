#pragma once
#include "Point.h"

class Triangle : public Object {
private:
    Point P1, P2, P3;

    double side(const Point& a, const Point& b) const;

public:
    void Init(Point a, Point b, Point c);

    double get_a() const;
    double get_b() const;
    double get_c() const;

    double get_A() const;
    double get_B() const;
    double get_C() const;

    double perimeter() const;
    double area() const;

    double heightA() const;
    double heightB() const;
    double heightC() const;

    void type() const;

    void Display() const;
};