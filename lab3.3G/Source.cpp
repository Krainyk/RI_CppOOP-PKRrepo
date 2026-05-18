#include "Triangle.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    cout << "Objects: " << Object::getCount() << endl;

    Point A(0, 0), B(4, 0), C(2, 3);

    Triangle t;
    t.Init(A, B, C);

    t.Display();

    cout << "Perimeter: " << t.perimeter() << endl;
    cout << "Area: " << t.area() << endl;

    cout << "Type: ";
    t.type();
    cout << endl;

    cout << "Objects: " << Object::getCount() << endl;

    return 0;
}