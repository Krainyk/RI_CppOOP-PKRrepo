#include "Header.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* head = NULL;

    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);

    if (hasDuplicates(head)) {
        cout << "Знайдено однакові елементи!" << endl;
    }
    else {
        cout << "Усі елементи унікальні." << endl;
    }

    return 0;
}