#include "Time.h"
#include <windows.h>
#include <iostream>
#include <exception>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        Time t1(2, 30);
        cout << "t1: " << t1 << endl;

        Time t2 = t1;
        cout << "t2: " << t2 << endl;

        ++t1;
        t2++;

        cout << "Після ++ :" << endl;
        cout << "t1: " << t1 << endl;
        cout << "t2: " << t2 << endl;

        --t1;

        cout << "Після -- :" << endl;
        cout << "t1: " << t1 << endl;

        cout << "В хвилинах: "
            << t1.minutes() << endl;

        string s = (string)t1;
        cout << "String: " << s << endl;

        Time t3 = makeTime(5, 45);
        cout << "t3: " << t3 << endl;

        Time bad(-1, 70);
    }
    catch (const invalid_argument& e) {
        cout << "invalid_argument: "
            << e.what() << endl;
    }
    catch (const underflow_error& e) {
        cout << "underflow_error: "
            << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "exception: "
            << e.what() << endl;
    }

    try {
        throw bad_exception();
    }
    catch (const bad_exception& e) {
        cout << "bad_exception: "
            << e.what() << endl;
    }

    return 0;
}