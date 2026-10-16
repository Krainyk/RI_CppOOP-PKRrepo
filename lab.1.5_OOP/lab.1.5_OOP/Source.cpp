#include "Header.h"
#include <iostream>
#include <cmath>
using namespace std;

void Pair::Init(double a, double b) {
    setFirst(a);
    setSecond(b);
}

void Pair::Read() {
    cout << "Enter first: ";
    cin >> first;
    cout << "Enter second: ";
    cin >> second;
}

void Pair::Display() const {
    cout << "First: " << first << ", Second: " << second << endl;
}

string Pair::toString() const {
    return "First = " + to_string(first) +
        ", Second = " + to_string(second);
}

double Pair::product() const {
    return first * second;
}

void RightAngled::Init(double a, double b) {
    legs.Init(a, b);
}

void RightAngled::Read() {
    legs.Read();
}

void RightAngled::Display() const {
    cout << "Triangle legs: ";
    legs.Display();
}

string RightAngled::toString() const {
    return "Triangle: " + legs.toString();
}

double RightAngled::hypotenuse() const {
    return sqrt(pow(legs.getFirst(), 2) +
        pow(legs.getSecond(), 2));
}

double RightAngled::area() const {
    return (legs.getFirst() * legs.getSecond()) / 2;
}