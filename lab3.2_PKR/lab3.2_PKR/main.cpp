#include "Header.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* head = NULL;

    addNode(head, 10);
    addNode(head, 20);
    addNode(head, 30);
    addNode(head, 50);

    if (hasDuplicates(head)) {
        cout << "Знайдено однакові елементи!" << endl;
    }
    else {
        cout << "Усі елементи унікальні." << endl;
    }

    return 0;
}