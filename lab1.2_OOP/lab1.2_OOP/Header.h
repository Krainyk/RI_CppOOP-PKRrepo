// Remove the duplicate class declaration and function declaration from the header.
// Only declare the function prototype for makeVector, not the class itself.

#pragma once
class Vector {
private:
    int* data;
    int size;
    int state;

public:
    void Init();
    Vector();
    ~Vector();
    int getSize() const;
    int getState() const;
    void setSize(int newSize);
    void allocateMemory(int newSize);
    void setElement(int index, int value);
    int getElement(int index);
    void Read();
    void Display() const;
    double getNorm() const;
};

Vector makeVector(int size);