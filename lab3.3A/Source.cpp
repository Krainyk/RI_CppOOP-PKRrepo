#include "BitStringPub.h"
#include "BitStringPriv.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Â²ÄÊÐÈÒÅ ÓÑÏÀÄÊÓÂÀÍÍß" << endl;
    BitStringPub pub1(15, 255);
    BitStringPub pub2;

    cout << "Ââåäåííÿ pub2:" << endl;
    cin >> pub2; 

    cout << "\npub1: " << pub1 << endl;
    cout << "pub2 ó äâ³éêîâîìó ôîðìàò³: " << string(pub2) << endl;
    cout << "pub1 & pub2: " << (pub1 & pub2) << endl;

    cout << "ÇÀÊÐÈÒÅ ÓÑÏÀÄÊÓÂÀÍÍß (Private)" << endl;
    BitStringPriv priv1(3, 3);
    BitStringPriv priv2(1, 1);

    cout << "priv1: " << priv1 << endl;
    cout << "~priv1 (NOT): " << ~priv1 << endl;
    cout << "priv1 | priv2 (OR): " << (priv1 | priv2) << endl;

    return 0;
}