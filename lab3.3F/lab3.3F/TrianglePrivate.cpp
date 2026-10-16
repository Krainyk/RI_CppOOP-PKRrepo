#include "TrianglePrivate.h"

void TrianglePrivate::Init(Point a, Point b, Point c) {
    A = a;
    B = b;
    C = c;
}

double TrianglePrivate::perimeter() const {
    double ab = A.distanceTo(B);
    double bc = B.distanceTo(C);
    double ca = C.distanceTo(A);
    return ab + bc + ca;
}

double TrianglePrivate::area() const {
    double a = A.distanceTo(B);
    double b = B.distanceTo(C);
    double c = C.distanceTo(A);
    double p = perimeter() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void TrianglePrivate::Display() const {
    cout << "TrianglePrivate: ";
    A.Display(); cout << " ";
    B.Display(); cout << " ";
    C.Display(); cout << endl;
}