#pragma once
#include <iostream>
#include <string>
using namespace std;

class BitString {
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
    void Read();
    void Display() const;
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