#pragma once
#include "B1.h"

class D1 : public B1 {
protected:
    int d1;

public:
    D1(int b, int d);
    ~D1();

    void show() const;
};