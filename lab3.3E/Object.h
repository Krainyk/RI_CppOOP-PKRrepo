#pragma once
#include <iostream>
using namespace std;

class Object {
private:
    static int count;

public:
    Object();

    ~Object();

    static int getCount();
};