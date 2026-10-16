#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x, y;

public:
    void Init(double x0, double y0);

    double getX() const { return x; }
    double getY() const { return y; }

    double distanceTo(const Point& p) const;

    void Display() const;
};