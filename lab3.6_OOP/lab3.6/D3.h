#pragma once
#include "D2.h"

class D3 : public D2 {
private:
    int d3;

public:
    D3(int b1, int d1, int b2, int d2, int d3);
    ~D3();

    void show() const;
};