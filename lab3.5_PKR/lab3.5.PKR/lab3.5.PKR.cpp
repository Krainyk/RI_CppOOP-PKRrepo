#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file("expressions.txt");
    if (!file.is_open()) {
        cout << "Помилка: не вдалося відкрити файл expressions.txt!" << endl;
        return 1;
    }

    string expr;

    while (getline(file, expr)) {
        processExpression(expr);
    }

    file.close();
    return 0;
}