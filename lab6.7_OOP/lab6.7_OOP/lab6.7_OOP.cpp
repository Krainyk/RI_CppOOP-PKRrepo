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

    Array arr;
    cout << "Початковий випадковий масив: " << endl;
    for (int i = 0; i < 10; i++) {
        arr.push_back(rand() % 101 - 50);
    }
    printArray(arr);

    cout << "\n--- Сортуємо ТІЛЬКИ додатні числа (sort_if + IsPositive) ---" << endl;
    IsPositive posCondition;
    sortArray_if(arr, posCondition);
    printArray(arr);

    cout << "\n--- Сортуємо всі елементи (sort) ---" << endl;
    sortArray(arr);
    printArray(arr);

    return 0;
}