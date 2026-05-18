#include "RightAngled.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

RightAngled::RightAngled(double a, double b) : Pair(a, b) {}

void RightAngled::setFirst(double value) {
    if (value <= 0) exit(1);
    Pair::setFirst(value);
}

void RightAngled::setSecond(double value) {
    if (value <= 0) exit(1);
    Pair::setSecond(value);
}

void RightAngled::Read() {
    double a, b;
    cout << "¬вед≥ть катет 1: ";
    cin >> a;
    cout << "¬вед≥ть катет 2: ";
    cin >> b;

    setFirst(a);
    setSecond(b);
}

void RightAngled::Display() const {
    cout << string(*this) << endl;
}

RightAngled::operator string() const {
    return "RightAngled(" + to_string(getFirst()) + ", " + to_string(getSecond()) + ")";
}

double RightAngled::hypotenuse() const {
    return sqrt(getFirst() * getFirst() + getSecond() * getSecond());
}

double RightAngled::area() const {
    return (getFirst() * getSecond()) / 2.0;
}