#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace std;


int main() {
    Point A, B, C;
    A.Init(0, 0);
    B.Init(3, 0);
    C.Init(0, 4);

    Triangle t;
    t.Init(A, B, C);

    t.Display();

    cout << "Perimeter: " << t.perimeter() << endl;
    cout << "Area: " << t.area() << endl;

    cout << "Heights: "
        << t.heightA() << ", "
        << t.heightB() << ", "
        << t.heightC() << endl;

    cout << "Type: ";
    t.type();

    cout << "Angles: "
        << t.get_A() << ", "
        << t.get_B() << ", "
        << t.get_C() << endl;

    return 0;
}