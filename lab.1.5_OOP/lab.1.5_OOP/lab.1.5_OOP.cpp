#include "Header.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    RightAngled t1;
    t1.Init(3, 4);

    t1.Display();
    cout << "Hypotenuse: " << t1.hypotenuse() << endl;
    cout << "Area: " << t1.area() << endl;

    cout << endl;

    RightAngled t2;
    t2.Read();

    cout << t2.toString() << endl;
    cout << "Hypotenuse: " << t2.hypotenuse() << endl;
    cout << "Area: " << t2.area() << endl;

    cout << endl;

    RightAngled arr[2];

    for (int i = 0; i < 2; i++) {
        cout << "Triangle " << i + 1 << endl;
        arr[i].Read();
    }

    for (int i = 0; i < 2; i++) {
        cout << "Triangle " << i + 1 << ": ";
        arr[i].Display();
    }

    return 0;
}