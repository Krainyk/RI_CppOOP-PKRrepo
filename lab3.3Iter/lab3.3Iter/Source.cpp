#include <iostream>
#include <string>
#include <windows.h>
#include "List.h"

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
        cout << "\n=== МЕНЮ ДВОНАПРАВЛЕНОГО СПИСКУ ===\n";
        cout << "1. Додати елемент в кінець списку\n";
        cout << "2. Вивести список на екран\n";
        cout << "3. ВИКОНАТИ ЗАВДАННЯ (видалити елементи перед заданим значенням)\n";
        cout << "4. Очистити весь список\n";
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
                cout << "Список порожній, немає що видаляти.\n";
                break;
            }
            int target = getValidInt("Введіть значення, ПЕРЕД яким треба видалити: ");
            head = deletePrecedingNodes(head, target);
            cout << "Операцію виконано!\n";
            printList(head);
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