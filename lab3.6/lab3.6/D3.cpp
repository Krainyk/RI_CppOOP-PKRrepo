#include "D3.h"

D3::D3(int b1, int d1, int b2, int d2, int d3)
    : D2(b1, d1, b2, d2), d3(d3) {
}

D3::~D3() {}

void D3::show() const {
    cout << "D3: " << d3 << endl;
    D2::show();
}