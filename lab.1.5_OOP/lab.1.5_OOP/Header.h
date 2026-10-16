#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pair {
private:
    double first;
    double second;

public:
    double getFirst() const { return first; }
    double getSecond() const { return second; }

    void setFirst(double value) { first = value; }
    void setSecond(double value) { second = value; }

    void Init(double a, double b);

    void Read();

    void Display() const;

    string toString() const;

    double product() const;
};

class RightAngled {
private:
    Pair legs;

public:
    Pair getLegs() const { return legs; }
    void setLegs(Pair p) { legs = p; }

    void Init(double a, double b);

    void Read();

    void Display() const;

    string toString() const;

    double hypotenuse() const;

    double area() const;
};