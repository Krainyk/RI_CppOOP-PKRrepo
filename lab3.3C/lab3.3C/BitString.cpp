#include "BitString.h"

BitString::BitString() : Object(), firstPart(0), secondPart(0) {}

BitString::BitString(long f, long s) : Object() {
    Init(f, s);
}

BitString::BitString(const BitString& other)
    : Object(other)
{
    firstPart = other.firstPart;
    secondPart = other.secondPart;
}

long BitString::getFirstPart() const { return firstPart; }
long BitString::getSecondPart() const { return secondPart; }

void BitString::setFirstPart(long value) {
    firstPart = value & 0xFF;
}

void BitString::setSecondPart(long value) {
    secondPart = value & 0xFF;
}

void BitString::Init(long f, long s) {
    setFirstPart(f);
    setSecondPart(s);
}

string toBinary(long value) {
    string r = "";
    for (int i = 7; i >= 0; i--)
        r += (value & (1 << i)) ? '1' : '0';
    return r;
}

string BitString::toString() const {
    return toBinary(firstPart) + " " + toBinary(secondPart);
}

BitString& BitString::operator=(const BitString& other) {
    if (this != &other) {
        firstPart = other.firstPart;
        secondPart = other.secondPart;
    }
    return *this;
}

BitString BitString::operator~() const {
    return BitString(~firstPart & 0xFF, ~secondPart & 0xFF);
}

BitString BitString::operator&(const BitString& other) const {
    return BitString(firstPart & other.firstPart,
        secondPart & other.secondPart);
}

BitString BitString::operator|(const BitString& other) const {
    return BitString(firstPart | other.firstPart,
        secondPart | other.secondPart);
}

BitString& BitString::operator++() {
    firstPart = (firstPart << 1) & 0xFF;
    secondPart = (secondPart << 1) & 0xFF;
    return *this;
}

BitString BitString::operator++(int) {
    BitString temp(*this);
    ++(*this);
    return temp;
}

BitString& BitString::operator--() {
    firstPart = (firstPart >> 1) & 0xFF;
    secondPart = (secondPart >> 1) & 0xFF;
    return *this;
}

BitString BitString::operator--(int) {
    BitString temp(*this);
    --(*this);
    return temp;
}

BitString::operator string() const {
    return toString();
}

istream& operator>>(istream& in, BitString& b) {
    long f, s;
    in >> f >> s;
    b.Init(f, s);
    return in;
}

ostream& operator<<(ostream& out, const BitString& b) {
    out << b.toString();
    return out;
}