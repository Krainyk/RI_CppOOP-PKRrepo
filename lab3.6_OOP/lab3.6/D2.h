#pragma once
#include "D1.h"
#include "B2.h"

class D2 : private D1, private B2 {
protected:
    int d2;

public:
    D2(int b1, int d1, int b2, int d2);
    ~D2();

    void show() const;
};