#pragma once
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
};

Array processArray(int* arr, int size);
