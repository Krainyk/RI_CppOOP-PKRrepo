#include "RightAngled.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

Pair::Pair(double a, double b) {
    setFirst(a);
    setSecond(b);
}

void Pair::setFirst(double value) {
    first = value;
}

void Pair::setSecond(double value) {
    second = value;
}

void Pair::Read() {
    double a, b;
    cout << "Введіть перше число: "; cin >> a;
    cout << "Введіть друге число: "; cin >> b;
    setFirst(a);
    setSecond(b);
}

void Pair::Display() const {
    cout << string(*this) << endl;
}

Pair::operator string() const {
    return "Pair(" + to_string(first) + ", " + to_string(second) + ")";
}

double Pair::product() const {
    return first * second;
}


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