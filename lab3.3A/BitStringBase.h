#pragma once
#include <iostream>
#include <string>
using namespace std;

class BitStringBase {
private:
    unsigned long firstPart;
    unsigned long secondPart;

protected:
    string toBinary(unsigned long value) const {
        string res = "";
        for (int i = 31; i >= 0; i--) {
            res += (value & (1UL << i)) ? '1' : '0';
        }
        return res;
    }

public:
    BitStringBase(unsigned long f = 0, unsigned long s = 0) : firstPart(f), secondPart(s) {}
    BitStringBase(const BitStringBase& other) : firstPart(other.firstPart), secondPart(other.secondPart) {}

    unsigned long getFirst() const { return firstPart; }
    unsigned long getSecond() const { return secondPart; }
    void setFirst(unsigned long v) { firstPart = v; }
    void setSecond(unsigned long v) { secondPart = v; }

    friend istream& operator>>(istream& in, BitStringBase& obj) {
        cout << "¬вед≥ть 1-у частину: "; in >> obj.firstPart;
        cout << "¬вед≥ть 2-у частину: "; in >> obj.secondPart;
        return in;
    }

    friend ostream& operator<<(ostream& out, const BitStringBase& obj) {
        out << "[" << obj.firstPart << " | " << obj.secondPart << "]";
        return out;
    }
};