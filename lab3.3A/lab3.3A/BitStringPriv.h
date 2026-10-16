#pragma once
#include "BitStringBase.h"

class BitStringPriv : private BitStringBase {
public:
    BitStringPriv(unsigned long f = 0, unsigned long s = 0) : BitStringBase(f, s) {}

    BitStringPriv& operator=(const BitStringPriv& other) {
        setFirst(other.getFirst());
        setSecond(other.getSecond());
        return *this;
    }

    BitStringPriv operator~() const {
        return BitStringPriv(~getFirst(), ~getSecond());
    }

    friend BitStringPriv operator|(const BitStringPriv& a, const BitStringPriv& b) {
        return BitStringPriv(a.getFirst() | b.getFirst(), a.getSecond() | b.getSecond());
    }

    friend istream& operator>>(istream& in, BitStringPriv& obj) {
        in >> (BitStringBase&)obj;
        return in;
    }

    friend ostream& operator<<(ostream& out, const BitStringPriv& obj) {
        out << (const BitStringBase&)obj;
        return out;
    }
};