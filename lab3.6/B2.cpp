#include "B2.h"

B2::B2(int x) : b2(x) {}

B2::~B2() {}

void B2::show() const {
    cout << "B2: " << b2 << endl;
}