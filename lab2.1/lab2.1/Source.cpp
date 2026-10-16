#include "Time.h"
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    

    Time t1(2, 30);
    cout << "t1: " << t1 << endl;

    Time t2 = t1;
    cout << "t2 (копія): " << t2 << endl;

    ++t1;
    t2++;

    cout << "Після інкременту:\n";
    cout << "t1: " << t1 << endl;
    cout << "t2: " << t2 << endl;

    cout << "В хвилинах: " << t1.minutes() << endl;

    string s = (string)t1;
    cout << "String: " << s << endl;

    Time t3 = makeTime(5, 45);
    cout << "t3: " << t3 << endl;

    return 0;
}