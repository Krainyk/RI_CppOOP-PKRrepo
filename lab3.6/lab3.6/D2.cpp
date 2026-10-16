#include "D2.h"

D2::D2(int b1, int d1, int b2, int d2)
    : D1(b1, d1), B2(b2), d2(d2) {
}

D2::~D2() {}

void D2::show() const {
    cout << "D2: " << d2 << endl;
    D1::show();
    B2::show();
}