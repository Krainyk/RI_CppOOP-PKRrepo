#pragma once
#include <string>
using namespace std;

class BitString {
private:
	long firstPart;
	long secondPart;
public:
	long getfirstPart() const { return firstPart; }
	long getsecondPart() const { return secondPart; }
	void setfirstPart(long value);
	void setsecondPart(long value);
	void Init(long f, long s);
	void Read();
	void Display() const;
	string toString() const;
	BitString Not() const;
	BitString And(const BitString& other) const;
	BitString Or(const BitString& other) const;
};