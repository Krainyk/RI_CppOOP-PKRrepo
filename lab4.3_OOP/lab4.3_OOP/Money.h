#pragma once
#include "Array.h"

class Money : public Array {
public:
    Money(int s = 1);

    void Read() override;
    void Display() const override;

    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;

    bool operator==(const Money& other) const;
    bool operator<(const Money& other) const;

    long long toNumber() const;
    void fromNumber(long long value);
};