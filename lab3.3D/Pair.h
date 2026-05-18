#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pair {
private:
    double first;
    double second;

public:
    Pair(double a = 0, double b = 0);
    ~Pair() {}

    double getFirst() const { return first; }
    double getSecond() const { return second; }

    void setFirst(double value);
    void setSecond(double value);

    void Read();
    void Display() const;

    operator string() const;

    double product() const;
};