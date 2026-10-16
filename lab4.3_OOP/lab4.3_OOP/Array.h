#pragma once
#include <iostream>
using namespace std;

class Array {
protected:
    unsigned char data[100];
    int size;

public:
    Array(int s = 1);

    virtual void Read() = 0;
    virtual void Display() const = 0;

    virtual ~Array() {}
};