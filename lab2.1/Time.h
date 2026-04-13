#pragma once
#include <iostream>
#include <string>
using namespace std;

class Time {
private:
    int first;
    int second;

public:
    Time();
    Time(int h, int m);
    Time(const Time& t);

    int GetHours() const;
    int GetMinutes() const;

    void SetHours(int h);
    void SetMinutes(int m);

    void Init(int h, int m);
    void Display() const;
    int minutes() const;

    Time& operator=(const Time& t);

    Time& operator++();
    Time operator++(int);   

    Time& operator--();
    Time operator--(int);

    operator string() const;

    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);
};

Time makeTime(int h, int m);