#include "RightAngled.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Перший трикутник" << endl;
    RightAngled t1(3, 4);
    t1.Display();
    cout << "Гіпотенуза: " << t1.hypotenuse() << endl;
    cout << "Площа: " << t1.area() << endl;

    cout << "Другий трикутник" << endl;
    RightAngled t2;
    t2.Read();     
    t2.Display();
    cout << "Гіпотенуза: " << t2.hypotenuse() << endl;
    cout << "Площа: " << t2.area() << endl;

    return 0;
}