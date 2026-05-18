#pragma once
#include "RightAngled.h"

class RightAngledPriv : private Pair {
public:
    RightAngledPriv(double a = 1, double b = 1);

    void Read();
    void Display() const;

    double hypotenuse() const;
    double area() const;
};