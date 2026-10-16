#include <iostream>
#include "BitString.h"
using namespace std;

int main() {
    cout << "Count: " << Object::getCount() << endl;

    BitString b1, b2;
    cout << "After create: " << Object::getCount() << endl;

    BitString b3 = b1;
    cout << "After copy: " << Object::getCount() << endl;

    {
        BitString temp;
        cout << "Inside block: " << Object::getCount() << endl;
    }

    cout << "After block: " << Object::getCount() << endl;

    return 0;
}