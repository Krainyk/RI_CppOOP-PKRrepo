#pragma once
#include <iostream>
using namespace std;

class Array {
private:
    double* data;
    int capacity;
    int size;

public:
    Array();

    Array(const Array& other);

    ~Array();

    void push_back(double value);

    int getSize() const;

    double operator[](int index) const;

    double& operator[](int index);
};

class IsPositive {
public:
    bool operator()(double value) const;
};

class IsEven {
public:
    bool operator()(double value) const;
};

template <typename Container>
void sortArray(Container& arr) {
    int n = arr.getSize();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <typename Container, typename Predicate>
void sortArray_if(Container& arr, Predicate pred) {
    int n = arr.getSize();
    for (int i = 0; i < n - 1; i++) {
        if (!pred(arr[i])) continue;

        for (int j = i + 1; j < n; j++) {
            if (!pred(arr[j])) continue;

            if (arr[i] > arr[j]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template <typename Container>
void printArray(const Container& arr) {
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}