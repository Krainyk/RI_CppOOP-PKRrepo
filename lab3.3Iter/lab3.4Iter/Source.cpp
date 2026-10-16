#include <iostream>
#include <string>
#include <Windows.h>
#include "CircularList.h"

using namespace std;

int getValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(10000, '\n');
            return value;
        }
        cout << "Помилка: Введіть коректне ціле число!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    Node* head = nullptr;
    int choice;

    while (true) {
        cout << "\n=== МЕНЮ КІЛЬЦЕВОГО СПИСКУ ===\n";
        cout << "1. Додати елемент\n";
        cout << "2. Вивести список на екран\n";
        cout << "3. ВИКОНАТИ ЗАВДАННЯ (Порахувати непарні елементи)\n";
        cout << "4. Очистити список\n";
        cout << "0. Вийти\n";

        choice = getValidInt("Ваш вибір: ");

        switch (choice) {
        case 1: {
            int val = getValidInt("Введіть ціле число: ");
            head = appendNode(head, val);
            cout << "Елемент додано.\n";
            break;
        }
        case 2:
            printList(head);
            break;
        case 3: {
            if (!head) {
                cout << "Список порожній, непарних елементів: 0\n";
                break;
            }
            int oddCount = countOddElements(head);
            cout << "Кількість непарних елементів у списку: " << oddCount << "\n";
            break;
        }
        case 4:
            destroyList(head);
            head = nullptr;
            cout << "Список очищено.\n";
            break;
        case 0:
            destroyList(head);
            cout << "Завершення роботи.\n";
            return 0;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }
}