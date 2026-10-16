#include <iostream>
#include "D3.h"
using namespace std;

int main() {
    B1 b1(1);
    B2 b2(2);
    D1 d1(1, 10);
    D2 d2(1, 10, 2, 20);
    D3 d3(1, 10, 2, 20, 30);

    cout << "Size B1: " << sizeof(b1) << endl;
    cout << "Size B2: " << sizeof(b2) << endl;
    cout << "Size D1: " << sizeof(d1) << endl;
    cout << "Size D2: " << sizeof(d2) << endl;
    cout << "Size D3: " << sizeof(d3) << endl;

    cout << "Show:\n";
    b1.show();
    b2.show();
    d1.show();
    d2.show();
    d3.show();

    return 0;
}