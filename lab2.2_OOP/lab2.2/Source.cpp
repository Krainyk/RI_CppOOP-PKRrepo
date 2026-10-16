#include "Matrix.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    Matrix A(2, 2), B(2, 2);

    cout << "Заповнення матриці A:\n";
    cin >> A;
    cout << "Заповнення матриці B:\n";
    cin >> B;

    cout << "\nМатриця A:\n" << A;
    cout << "Матриця B:\n" << B;

    Matrix C = A + B;
    cout << "Результат A + B:\n" << C;

    A *= 10;
    cout << "A після A *= 10:\n" << A;

    return 0;
}