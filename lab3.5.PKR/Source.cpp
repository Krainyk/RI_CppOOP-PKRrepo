#include "Header.h"
#include <iostream>
#include <stack>
using namespace std;

void processExpression(const string& expr) {
    if (expr.empty()) return;

    cout << "Вираз: " << expr << endl;

    stack<char> s;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] != ' ') {
            s.push(expr[i]);
        }
    }

    stack<char> tempStack = s;
    cout << "Стек (зверху вниз): ";
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    int operands = 0;
    int operations = 0;

    while (!s.empty()) {
        char c = s.top();
        s.pop();

        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            operations++;
        }
        else if (c != '(' && c != ')') {
            operands++;
        }
    }

    cout << "Операндів: " << operands << endl;
    cout << "Операцій: " << operations << endl;
    cout << "----------------------" << endl;
}