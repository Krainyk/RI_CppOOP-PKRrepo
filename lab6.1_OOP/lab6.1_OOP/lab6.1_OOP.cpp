#include "Array.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    srand(time(0));

    int n;
    cout << "Введіть розмір початкового масиву: ";
    cin >> n;

    if (n <= 0) {
        cout << "Розмір має бути більшим за 0." << endl;
        return 1;
    }

    int* initialArray = new int[n];

    cout << "\nПочатковий масив (від -50 до +50):" << endl;
    for (int i = 0; i < n; i++) {
        initialArray[i] = rand() % 101 - 50;
        cout << initialArray[i] << " ";
    }
    cout << endl;

    Array resultArray = processArray(initialArray, n);

    cout << "\nРезультуючий масив:" << endl;
    for (int i = 0; i < resultArray.getSize(); i++) {
        cout << resultArray[i] << " ";
    }
    cout << endl;

    delete[] initialArray;

    return 0;
}