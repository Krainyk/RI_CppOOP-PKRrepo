#include "Triangle.h"
#include <cmath>
#include <iostream>
using namespace std;

void Triangle::Init(Point a, Point b, Point c) {
    P1 = a;
    P2 = b;
    P3 = c;
}

double Triangle::side(const Point& a, const Point& b) const {
    return a.distanceTo(b);
}

double Triangle::get_a() const { return side(P2, P3); }
double Triangle::get_b() const { return side(P1, P3); }
double Triangle::get_c() const { return side(P1, P2); }

double Triangle::perimeter() const {
    return get_a() + get_b() + get_c();
}

double Triangle::area() const {
    double a = get_a(), b = get_b(), c = get_c();
    double p = perimeter() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::heightA() const { return 2 * area() / get_a(); }
double Triangle::heightB() const { return 2 * area() / get_b(); }
double Triangle::heightC() const { return 2 * area() / get_c(); }

void Triangle::type() const {
    double a = get_a(), b = get_b(), c = get_c();

    if (a == b && b == c)
        cout << "Рівносторонній";
    else if (a == b || b == c || a == c)
        cout << "Рівнобедрений";
    else if (fabs(a * a + b * b - c * c) < 0.001 ||
        fabs(a * a + c * c - b * b) < 0.001 ||
        fabs(b * b + c * c - a * a) < 0.001)
        cout << "Прямокутний";
    else
        cout << "Різносторонній";
}

double Triangle::get_A() const {
    return acos((get_b() * get_b() + get_c() * get_c() - get_a() * get_a()) /
        (2 * get_b() * get_c()));
}

double Triangle::get_B() const {
    return acos((get_a() * get_a() + get_c() * get_c() - get_b() * get_b()) /
        (2 * get_a() * get_c()));
}

double Triangle::get_C() const {
    return acos((get_a() * get_a() + get_b() * get_b() - get_c() * get_c()) /
        (2 * get_a() * get_b()));
}

void Triangle::Display() const {
    cout << "P1="; P1.Display();
    cout << " P2="; P2.Display();
    cout << " P3="; P3.Display();
    cout << endl;
}