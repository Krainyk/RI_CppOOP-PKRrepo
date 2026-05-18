#pragma once
#include <iostream>
using namespace std;

class Object {
protected:
    static int count;

public:
    Object();
    virtual ~Object();

    static int getCount();
};