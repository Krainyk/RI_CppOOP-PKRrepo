#include "BitString.h"

BitString::BitString() : firstPart(0), secondPart(0) {}

BitString::BitString(long f, long s) {
    Init(f, s);
}

BitString::BitString(const BitString& other) {
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

void BitString::Read() {
    long f, s;
    cout << "¬вед≥ть першу частину: ";
    cin >> f;
    cout << "¬вед≥ть другу частину: ";
    cin >> s;
    Init(f, s);
}

void BitString::Display() const {
    cout << toString() << endl;
}

string toBinary(long value) {
    string result = "";
    for (int i = 7; i >= 0; i--) { // т≥льки 8 б≥т
        result += (value & (1 << i)) ? '1' : '0';
    }
    return result;
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
    BitString result;
    result.Init(~firstPart & 0xFF, ~secondPart & 0xFF);
    return result;
}

BitString BitString::operator&(const BitString& other) const {
    BitString result;
    result.Init(
        (firstPart & other.firstPart) & 0xFF,
        (secondPart & other.secondPart) & 0xFF
    );
    return result;
}

BitString BitString::operator|(const BitString& other) const {
    BitString result;
    result.Init(
        (firstPart | other.firstPart) & 0xFF,
        (secondPart | other.secondPart) & 0xFF
    );
    return result;
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
    cout << "¬вед≥ть першу частину: ";
    in >> f;
    cout << "¬вед≥ть другу частину: ";
    in >> s;
    b.Init(f, s);
    return in;
}

ostream& operator<<(ostream& out, const BitString& b) {
    out << b.toString();
    return out;
}