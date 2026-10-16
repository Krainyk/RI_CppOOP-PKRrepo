#include <iostream>
#include <windows.h>

#include "Hex.h"
#include "Money.h"

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "===== HEX =====" << endl;

    Hex h1, h2;

    h1.Read();
    h2.Read();

    cout << "h1 = ";
    h1.Display();

    cout << "h2 = ";
    h2.Display();

    Hex h3 = h1 + h2;

    cout << "h1 + h2 = ";
    h3.Display();

    cout << endl;

    cout << "===== MONEY =====" << endl;

    Money m1, m2;

    m1.Read();
    m2.Read();

    cout << "m1 = ";
    m1.Display();

    cout << "m2 = ";
    m2.Display();

    Money m3 = m1 + m2;

    cout << "m1 + m2 = ";
    m3.Display();

    cout << endl;

    cout << "===== POLYMORPHISM =====" << endl;

    Array* arr[2];

    arr[0] = new Hex();
    arr[1] = new Money();

    arr[0]->Read();
    arr[1]->Read();

    arr[0]->Display();
    arr[1]->Display();

    delete arr[0];
    delete arr[1];

    return 0;
}