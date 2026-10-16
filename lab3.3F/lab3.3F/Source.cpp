#include "TrianglePublic.h"
#include "TrianglePrivate.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Point A, B, C;
    A.Init(0, 0);
    B.Init(4, 0);
    C.Init(2, 3);

    cout << "=== Â²ÄÊÐÈÒÅ ÓÑÏÀÄÊÓÂÀÍÍß ===" << endl;
    TrianglePublic tp;
    tp.Init(A, B, C);
    tp.Display();
    cout << "Perimeter: " << tp.perimeter() << endl;
    cout << "Area: " << tp.area() << endl;

    cout << "=== ÇÀÊÐÈÒÅ ÓÑÏÀÄÊÓÂÀÍÍß ===" << endl;
    TrianglePrivate tr;
    tr.Init(A, B, C);
    tr.Display();
    cout << "Perimeter: " << tr.perimeter() << endl;
    cout << "Area: " << tr.area() << endl;

    return 0;
}