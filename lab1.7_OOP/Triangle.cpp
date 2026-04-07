#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace std;

void Point::Init(double x0, double y0) {
    x = x0;
    y = y0;
}
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
void Triangle::Init(Point a, Point b, Point c) {
    P1 = a;
    P2 = b;
    P3 = c;
}
double Triangle::side(const Point& a, const Point& b) const {
    return a.distanceTo(b);
}

double Triangle::perimeter() const {
    return get_a() + get_b() + get_c();
}

double Triangle::area() const {
    double a = get_a();
    double b = get_b();
    double c = get_c();
    double p = perimeter() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::type() const {
    double a = get_a();
    double b = get_b();
    double c = get_c();

    if (a == b && b == c)
        cout << "Equilateral" << endl;
    else if (a == b || b == c || a == c)
        cout << "Isosceles" << endl;
    else if (fabs(a * a + b * b - c * c) < 0.001 ||
        fabs(a * a + c * c - b * b) < 0.001 ||
        fabs(b * b + c * c - a * a) < 0.001)
        cout << "Right" << endl;
    else
        cout << "Scalene" << endl;
}

double Triangle::get_A() const {
    double a = get_a(), b = get_b(), c = get_c();
    return acos((b * b + c * c - a * a) / (2 * b * c));
}

double Triangle::get_B() const {
    double a = get_a(), b = get_b(), c = get_c();
    return acos((a * a + c * c - b * b) / (2 * a * c));
}

double Triangle::get_C() const {
    double a = get_a(), b = get_b(), c = get_c();
    return acos((a * a + b * b - c * c) / (2 * a * b));
}

void Triangle::Display() const {
    cout << "Triangle: ";
    P1.Display(); cout << " ";
    P2.Display(); cout << " ";
    P3.Display(); cout << endl;
}