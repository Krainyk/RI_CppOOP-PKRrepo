#include "RightAngled.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    RightAngled t1;
    t1.Init(3, 4);

    t1.Display();
    cout << "Гіпоенуза: " << t1.hypotenuse() << endl;
    cout << "Площат: " << t1.area() << endl;

    cout << endl;

    RightAngled t2;
    t2.Read();

    cout << t2.toString() << endl;
    cout << "Гіпотенуза: " << t2.hypotenuse() << endl;
    cout << "Площа: " << t2.area() << endl;

    return 0;
}