#include "Array.h"
#include <cmath>

Array::Array() {
    capacity = 10;
    size = 0;
    data = new double[capacity];
}

Array::Array(const Array& other) {
    size = other.size;
    capacity = other.capacity;
    if (size > capacity) {
        size = capacity;
    }
    data = new double[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

Array::~Array() {
    delete[] data;
}

void Array::push_back(double value) {
    if (size >= capacity) {
        capacity *= 2;
        double* newData = new double[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    if (size < capacity) {
        data[size++] = value;
    }
}

int Array::getSize() const {
    return size;
}

double Array::operator[](int index) const {
    return data[index];
}

Array processArray(int* arr, int size) {
    Array result;

    int firstNegative = 1;
    bool foundNegative = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            firstNegative = arr[i];
            foundNegative = true;
            break;
        }
    }

    double absSum = 0;

    for (int i = 0; i < size; i++) {
        double val = arr[i];

        if (arr[i] % 2 == 0) {
            val *= firstNegative;
        }

        result.push_back(val);
        absSum += abs(val);
    }

    double absMean = absSum / size;
    result.push_back(absSum);
    result.push_back(absMean);

    return result;
}