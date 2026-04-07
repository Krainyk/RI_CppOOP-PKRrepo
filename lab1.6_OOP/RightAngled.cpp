#include "RightAngled.h"
#include <iostream>
#include <cmath>
using namespace std;

void RightAngled::Pair::Init(double a, double b) {
    setFirst(a);
    setSecond(b);
}

void RightAngled::Pair::Read() {
    cout << "Введіть перше значення: ";
    cin >> first;
    cout << "Введіть друге значення: ";
    cin >> second;
}

void RightAngled::Pair::Display() const {
    cout << "Перше значення: " << first
        << ", Друге значення: " << second << endl;
}

string RightAngled::Pair::toString() const {
    return "Перше значення = " + to_string(first) +
        ", Друге значення = " + to_string(second);
}

double RightAngled::Pair::product() const {
    return first * second;
}

void RightAngled::Init(double a, double b) {
    legs.Init(a, b);
}

void RightAngled::Read() {
    legs.Read();
}

void RightAngled::Display() const {
    cout << "Катети: ";
    legs.Display();
}

string RightAngled::toString() const {
    return "Трикутник: " + legs.toString();
}

double RightAngled::hypotenuse() const {
    return sqrt(pow(legs.getFirst(), 2) +
        pow(legs.getSecond(), 2));
}

double RightAngled::area() const {
    return legs.product() / 2;
}