#include "Time.h"

Time::Time() : first(0), second(0) {}

Time::Time(int h, int m) {
    Init(h, m);
}

Time::Time(const Time& t) {
    first = t.first;
    second = t.second;
}

int Time::GetHours() const {
    return first;
}

int Time::GetMinutes() const {
    return second;
}

void Time::SetHours(int h) {
    if (h < 0)
        throw invalid_argument("Години не можуть бути менше 0");

    first = h;
}

void Time::SetMinutes(int m) {
    if (m < 0 || m >= 60)
        throw invalid_argument("Хвилини повинні бути в межах 0-59");

    second = m;
}

void Time::Init(int h, int m) {
    SetHours(h);
    SetMinutes(m);
}

int Time::minutes() const {
    return first * 60 + second;
}

void Time::Display() const {
    cout << first << " год " << second << " хв";
}

Time& Time::operator=(const Time& t) {
    if (this != &t) {
        first = t.first;
        second = t.second;
    }

    return *this;
}

Time& Time::operator++() {
    second++;

    if (second >= 60) {
        second = 0;
        first++;
    }

    return *this;
}

Time Time::operator++(int) {
    Time temp(*this);
    ++(*this);
    return temp;
}

Time& Time::operator--() {
    if (first == 0 && second == 0)
        throw underflow_error("Час не може бути менше 0");

    second--;

    if (second < 0) {
        second = 59;
        first--;
    }

    return *this;
}

Time Time::operator--(int) {
    Time temp(*this);
    --(*this);
    return temp;
}

Time::operator string() const {
    return to_string(first) + "h " + to_string(second) + "m";
}

istream& operator>>(istream& in, Time& t) {
    int h, m;

    cout << "Введіть години: ";
    in >> h;

    cout << "Введіть хвилини: ";
    in >> m;

    t.SetHours(h);
    t.SetMinutes(m);

    return in;
}

ostream& operator<<(ostream& out, const Time& t) {
    out << t.first << " год " << t.second << " хв";
    return out;
}

Time makeTime(int h, int m) {
    if (h < 0 || m < 0 || m >= 60)
        throw invalid_argument("Некоректний час");

    return Time(h, m);
}