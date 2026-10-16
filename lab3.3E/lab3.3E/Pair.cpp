#include "Pair.h"
#include <iostream>

using namespace std;

Pair::Pair(double a, double b) {
    setFirst(a);
    setSecond(b);
}

double Pair::getFirst() const {
    return first;
}

double Pair::getSecond() const {
    return second;
}

void Pair::setFirst(double value) {
    first = value;
}

void Pair::setSecond(double value) {
    second = value;
}

void Pair::Read() {
    double a, b;
    cout << "¬вед≥ть перше число: ";
    cin >> a;
    cout << "¬вед≥ть друге число: ";
    cin >> b;

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