#include "TrianglePublic.h"

void TrianglePublic::Init(Point a, Point b, Point c) {
    A = a;
    B = b;
    C = c;
}

double TrianglePublic::sideAB() const { return A.distanceTo(B); }
double TrianglePublic::sideBC() const { return B.distanceTo(C); }
double TrianglePublic::sideCA() const { return C.distanceTo(A); }

double TrianglePublic::perimeter() const {
    return sideAB() + sideBC() + sideCA();
}

double TrianglePublic::area() const {
    double a = sideAB(), b = sideBC(), c = sideCA();
    double p = perimeter() / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void TrianglePublic::Display() const {
    cout << "TrianglePublic: ";
    A.Display(); cout << " ";
    B.Display(); cout << " ";
    C.Display(); cout << endl;
}