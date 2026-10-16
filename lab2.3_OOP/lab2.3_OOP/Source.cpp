#include "BitString.h"
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BitString b1, b2;

    cin >> b1 >> b2;

    cout << "b1: " << b1 << endl;
    cout << "b2: " << b2 << endl;

    cout << "~b1: " << ~b1 << endl;
    cout << "b1 & b2: " << (b1 & b2) << endl;
    cout << "b1 | b2: " << (b1 | b2) << endl;

    ++b1;
    b2--;

    cout << "Ï³ñëÿ ++ ³ --:\n";
    cout << "b1: " << b1 << endl;
    cout << "b2: " << b2 << endl;

    string s = (string)b1;
    cout << "String: " << s << endl;

    return 0;
}