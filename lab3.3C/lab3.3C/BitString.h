#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class BitString : public Object {
private:
    unsigned long firstPart;
    unsigned long secondPart;

public:
    BitString();
    BitString(long f, long s);
    BitString(const BitString& other);

    long getFirstPart() const;
    long getSecondPart() const;

    void setFirstPart(long value);
    void setSecondPart(long value);

    void Init(long f, long s);
    string toString() const;

    BitString& operator=(const BitString& other);

    BitString operator~() const;
    BitString operator&(const BitString& other) const;
    BitString operator|(const BitString& other) const;

    BitString& operator++();
    BitString operator++(int);

    BitString& operator--();
    BitString operator--(int);

    operator string() const;

    friend istream& operator>>(istream& in, BitString& b);
    friend ostream& operator<<(ostream& out, const BitString& b);
};