#include "Header.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <windows.h>

using namespace std;

class Vector {
private:
    int* data;
    int size;
    int state;

public:
    void Init() {
        data = nullptr;
        size = 0;
        state = 0;
    }

    Vector() {
        Init();
    }

    ~Vector() {
        if (data != nullptr) {
            delete[] data;
        }
    }

    int getSize() const { return size; }
    int getState() const { return state; }

    void setSize(int newSize) {
        if (newSize <= 0) {
            cout << "Помилка: Неправильний розмір!\n";
            state = 2;
            return;
        }
        allocateMemory(newSize);
    }

    void allocateMemory(int newSize) {
        if (data != nullptr) {
            delete[] data;
        }

        try {
            data = new int[newSize];
            size = newSize;
            state = 0;
            for (int i = 0; i < size; i++) {
                data[i] = 0;
            }
        }
        catch (...) {
            state = 1;
            cout << "Помилка: Неможливо виділити пам'ять!\n";
            size = 0;
        }
    }

    void setElement(int index, int value) {
        if (index < 0 || index >= size) {
            state = 2;
            cout << "Помилка: Вихід за межі масиву (запис)!\n";
            return;
        }
        data[index] = value;
        state = 0;
    }

    int getElement(int index) {
        if (index < 0 || index >= size) {
            state = 2;
            cout << "Помилка: Вихід за межі масиву (зчитування)!\n";
            return 0;
        }
        state = 0;
        return data[index];
    }

    void Read() {
        int s;
        cout << "Введіть розмір вектора: ";
        cin >> s;
        setSize(s);

        if (state == 0) {
            cout << "Введіть " << size << " елементів:\n";
            for (int i = 0; i < size; i++) {
                int val;
                cin >> val;
                setElement(i, val);
            }
        }
    }

    void Display() const {
        if (size == 0 || data == nullptr) {
            cout << "Вектор порожній. Стан: " << state << "\n";
            return;
        }
        cout << "Вектор: [ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "] | Стан: " << state << "\n";
    }

    double getNorm() const {
        if (size == 0 || data == nullptr) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            sum += data[i] * data[i];
        }
        return sqrt(sum);
    }
};

Vector makeVector(int size) {
    if (size <= 0) {
        cout << "Критична помилка: Некоректний розмір для створення вектора! Роботу завершено.\n";
        exit(1);
    }

    Vector v;
    v.Init();
    v.setSize(size);
    return v;
}