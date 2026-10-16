#include "B1.h"

B1::B1(int x) : b1(x) {}

B1::~B1() {}

void B1::show() const {
    cout << "B1: " << b1 << endl;
}