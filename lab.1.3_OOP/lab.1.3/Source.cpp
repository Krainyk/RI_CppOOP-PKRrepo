#include "BitString.h"
#include <iostream>
#include <string>
using namespace std;

void BitString::setfirstPart(long value) {
	firstPart = value;
}

void BitString::setsecondPart(long value) {
	secondPart = value;
}

void BitString::Init(long f, long s) {
	setfirstPart(f);
	setsecondPart(s);
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
	cout << "ѕерша частина: " << firstPart << endl;
	cout << "ƒруга частина: " << secondPart << endl;
}

string BitString::toString() const {
	return std::to_string(firstPart) + " " + std::to_string(secondPart);
}

BitString BitString::Not() const {
	BitString result;
	result.Init(~firstPart, ~secondPart);
	return result;
}

BitString BitString::And(const BitString& other) const {
	BitString result;
	result.Init(firstPart & other.firstPart, secondPart & other.secondPart);
	return result;
}

BitString BitString::Or(const BitString& other) const {
	BitString result;
	result.Init(firstPart | other.firstPart, secondPart | other.secondPart);
	return result;
}