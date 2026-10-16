#include "Array.h"

Array::Array() {
    capacity = 10;
    size = 0;
    data = new double[capacity];
}

Array::Array(const Array& other) {
    size = other.size;
    capacity = other.capacity;
    if (size > capacity) size = capacity;
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

int Array::getSize() const { return size; }

double Array::operator[](int index) const { return data[index]; }

double& Array::operator[](int index) { return data[index]; }

bool IsPositive::operator()(double value) const {
    return value > 0;
}

bool IsEven::operator()(double value) const {
    return (int)value % 2 == 0;
}