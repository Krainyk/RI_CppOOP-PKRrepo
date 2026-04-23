#pragma once
using namespace std;

class Object {
protected:
    static int count;

public:
    Object();
    Object(const Object& obj);
    ~Object();

    static int getCount();
};