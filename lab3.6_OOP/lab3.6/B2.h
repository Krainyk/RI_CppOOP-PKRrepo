#pragma once
#include <iostream>
using namespace std;

class B2 {
protected:
    int b2;

public:
    B2(int x = 0);
    ~B2();

    void show() const;
};