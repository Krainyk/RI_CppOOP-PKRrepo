#include "Time.h"
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Time t1;
    cin >> t1;
    cout << t1 << endl;

    Time t2(2, 30);
    cout << "t2: " << t2 << endl;

    Time t3 = t2;
    cout << "t3 (копія): " << t3 << endl;

    ++t2;
    t3++;

    cout << "Після інкременту:\n";
    cout << "t2: " << t2 << endl;
    cout << "t3: " << t3 << endl;

    cout << "В хвилинах: " << t2.minutes() << endl;

    string s = (string)t2;
    cout << "String: " << s << endl;

    Time t4 = makeTime(5, 45);
    cout << "t4: " << t4 << endl;

    return 0;
}