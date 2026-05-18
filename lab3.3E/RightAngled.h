#pragma once
#include "Pair.h"

class RightAngled : public Pair {
public:
    RightAngled(double a = 1, double b = 1);

    void setFirst(double value);
    void setSecond(double value);

    void Read();
    void Display() const;

    operator string() const;

    double hypotenuse() const;
    double area() const;
};
