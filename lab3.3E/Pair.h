#pragma once
#include "Object.h"
#include <string>

using namespace std;

class Pair : public Object {
private:
    double first;
    double second;

public:
    Pair(double a = 0, double b = 0);

    ~Pair() {};

    double getFirst() const;
    double getSecond() const;

    void setFirst(double value);
    void setSecond(double value);

    void Read();
    void Display() const;

    operator string() const;

    double product() const;
};