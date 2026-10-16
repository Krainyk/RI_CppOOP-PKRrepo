#include "Money.h"

Money::Money(int s) : Array(s) {}

void Money::Read() {
    string str;

    cout << "¬вед≥ть суму (без крапки): ";
    cin >> str;

    size = str.length();

    for (int i = 0; i < size; i++) {
        data[i] = str[size - 1 - i] - '0';
    }
}

void Money::Display() const {

    for (int i = size - 1; i >= 0; i--) {

        if (i == 1)
            cout << ".";

        cout << (int)data[i];
    }

    cout << " грн" << endl;
}

long long Money::toNumber() const {
    long long result = 0;
    long long power = 1;

    for (int i = 0; i < size; i++) {
        result += data[i] * power;
        power *= 10;
    }

    return result;
}

void Money::fromNumber(long long value) {
    size = 0;

    do {
        data[size++] = value % 10;
        value /= 10;
    } while (value > 0);
}

Money Money::operator+(const Money& other) const {
    Money result;

    long long val =
        toNumber() + other.toNumber();

    result.fromNumber(val);

    return result;
}

Money Money::operator-(const Money& other) const {
    Money result;

    long long val =
        toNumber() - other.toNumber();

    result.fromNumber(val);

    return result;
}

bool Money::operator==(const Money& other) const {
    return toNumber() == other.toNumber();
}

bool Money::operator<(const Money& other) const {
    return toNumber() < other.toNumber();
}