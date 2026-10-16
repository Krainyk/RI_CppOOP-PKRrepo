#include "D1.h"

D1::D1(int b, int d) : B1(b), d1(d) {}

D1::~D1() {}

void D1::show() const {
    cout << "D1: " << d1 << endl;
    B1::show();
}