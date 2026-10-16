#pragma once
#include "Array.h"
#include <string>

class Hex : public Array {
public:
    Hex(int s = 1);

    void Read() override;
    void Display() const override;

    Hex operator+(const Hex& other) const;
    Hex operator-(const Hex& other) const;

    bool operator==(const Hex& other) const;
    bool operator<(const Hex& other) const;

    unsigned long long toDecimal() const;
    void fromDecimal(unsigned long long value);
};