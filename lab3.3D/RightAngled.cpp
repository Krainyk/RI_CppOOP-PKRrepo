#include "Pair.h"
#include "RightAngled.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

RightAngled::RightAngled(double a, double b) : Pair() {
    setFirst(a);
    setSecond(b);
}

void RightAngled::setFirst(double value) {
    if (value <= 0) {
        cout << "Помилка: катет не може бути меншим або дорівнювати 0!" << endl;
        exit(1);
    }
    Pair::setFirst(value);
}

void RightAngled::setSecond(double value) {
    if (value <= 0) {
        cout << "Помилка: катет не може бути меншим або дорівнювати 0!" << endl;
        exit(1);
    }
    Pair::setSecond(value);
}

void RightAngled::Read() {
    cout << "Введення катетів трикутника:" << endl;
    double a, b;
    cout << "Введіть перший катет: "; cin >> a;
    cout << "Введіть другий катет: "; cin >> b;

    setFirst(a);
    setSecond(b);
}

void RightAngled::Display() const {
    cout << string(*this) << endl;
}

RightAngled::operator string() const {
    return "RightAngled(катет1 = " + to_string(getFirst()) + ", катет2 = " + to_string(getSecond()) + ")";
}

double RightAngled::hypotenuse() const {
    return sqrt(getFirst() * getFirst() + getSecond() * getSecond());
}

double RightAngled::area() const {
    return (getFirst() * getSecond()) / 2.0;
}