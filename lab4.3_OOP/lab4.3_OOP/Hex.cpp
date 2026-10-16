#include "Hex.h"

Hex::Hex(int s) : Array(s) {}

void Hex::Read() {
    string str;

    cout << "¬вед≥ть HEX число: ";
    cin >> str;

    size = str.length();

    for (int i = 0; i < size; i++) {
        char c = str[size - 1 - i];

        if (c >= '0' && c <= '9')
            data[i] = c - '0';

        else if (c >= 'A' && c <= 'F')
            data[i] = c - 'A' + 10;

        else if (c >= 'a' && c <= 'f')
            data[i] = c - 'a' + 10;
    }
}

void Hex::Display() const {
    for (int i = size - 1; i >= 0; i--) {

        if (data[i] < 10)
            cout << (int)data[i];
        else
            cout << char(data[i] - 10 + 'A');
    }

    cout << endl;
}

unsigned long long Hex::toDecimal() const {
    unsigned long long result = 0;
    unsigned long long power = 1;

    for (int i = 0; i < size; i++) {
        result += data[i] * power;
        power *= 16;
    }

    return result;
}

void Hex::fromDecimal(unsigned long long value) {
    size = 0;

    do {
        data[size++] = value % 16;
        value /= 16;
    } while (value > 0);
}

Hex Hex::operator+(const Hex& other) const {
    Hex result;

    unsigned long long val =
        toDecimal() + other.toDecimal();

    result.fromDecimal(val);

    return result;
}

Hex Hex::operator-(const Hex& other) const {
    Hex result;

    unsigned long long val =
        toDecimal() - other.toDecimal();

    result.fromDecimal(val);

    return result;
}

bool Hex::operator==(const Hex& other) const {
    return toDecimal() == other.toDecimal();
}

bool Hex::operator<(const Hex& other) const {
    return toDecimal() < other.toDecimal();
}