#pragma once
#include <iostream>
using namespace std;

class B1 {
protected:
    int b1;

public:
    B1(int x = 0);
    ~B1();

    void show() const;
};