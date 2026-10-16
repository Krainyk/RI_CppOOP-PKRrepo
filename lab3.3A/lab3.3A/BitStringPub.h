#pragma once
#include "BitStringBase.h"

class BitStringPub : public BitStringBase {
public:
    BitStringPub(unsigned long f = 0, unsigned long s = 0) : BitStringBase(f, s) {}

    BitStringPub& operator=(const BitStringPub& other) {
        setFirst(other.getFirst());
        setSecond(other.getSecond());
        return *this;
    }

    operator string() const {
        return toBinary(getFirst()) + " " + toBinary(getSecond());
    }

    BitStringPub operator~() const {
        return BitStringPub(~getFirst(), ~getSecond());
    }

    friend BitStringPub operator&(const BitStringPub& a, const BitStringPub& b) {
        return BitStringPub(a.getFirst() & b.getFirst(), a.getSecond() & b.getSecond());
    }
};