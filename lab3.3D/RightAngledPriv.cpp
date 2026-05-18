#include "RightAngledPriv.h"
#include <cmath>

RightAngledPriv::RightAngledPriv(double a, double b) : Pair(a, b) {
}

void RightAngledPriv::Read() {
    Pair::Read();
}

void RightAngledPriv::Display() const {
    cout << "RightAngledPriv: "
        << getFirst() << ", "
        << getSecond() << endl;
}

double RightAngledPriv::hypotenuse() const {
    return sqrt(getFirst() * getFirst()
        + getSecond() * getSecond());
}

double RightAngledPriv::area() const {
    return getFirst() * getSecond() / 2.0;
}