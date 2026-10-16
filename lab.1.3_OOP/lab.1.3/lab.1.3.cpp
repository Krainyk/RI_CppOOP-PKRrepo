#include "BitString.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	BitString bitString1, bitString2;
	bitString1.Read();
	bitString2.Read();
	cout << "BitString 1:" << endl;
	bitString1.Display();
	cout << "BitString 2:" << endl;
	bitString2.Display();
	BitString notBitString1 = bitString1.Not();
	cout << "NOT BitString 1:" << endl;
	notBitString1.Display();
	BitString andResult = bitString1.And(bitString2);
	cout << "BitString 1 AND BitString 2:" << endl;
	andResult.Display();
	BitString orResult = bitString1.Or(bitString2);
	cout << "BitString 1 OR BitString 2:" << endl;
	orResult.Display();
	return 0;
}