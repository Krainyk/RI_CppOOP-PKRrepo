#include "RightAngled.h"
#include "Object.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Об'єктів зараз: " << Object::getCount() << endl;

    RightAngled t1(3, 4);
    RightAngled t2;
    RightAngled t3;

    cout << "Після створення: " << Object::getCount() << endl;

    t2.Read();

    cout << "t1: ";
    t1.Display();
    cout << "Гіпотенуза: " << t1.hypotenuse() << endl;
    cout << "Площа: " << t1.area() << endl;

    cout << "t2: ";
    t2.Display();

    cout << "Перед завершенням: " << Object::getCount() << endl;

    return 0;
}