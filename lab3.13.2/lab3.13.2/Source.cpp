#include <iostream>
#include <vector>
#include <string>
#include <windows.h>    
#include "Product.h"
#include "ClosedHash.h"

using namespace std;

double getValidDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0) {
            cin.ignore(10000, '\n');
            return value;
        }
        cout << "Помилка: Введіть коректне додатне число!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

string getValidString(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

void printProductList(const vector<Product>& list) {
    if (list.empty()) {
        cout << "Товарів не знайдено.\n";
        return;
    }
    cout << "------------------------------------------------------\n";
    for (const auto& p : list) {
        cout << "Назва: " << p.name << " | Магазин: " << p.store
            << " | Ціна: " << p.price << " грн | Кількість: "
            << p.quantity << " " << p.unit << "\n";
    }
    cout << "------------------------------------------------------\n";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    ClosedHashTable myTable = createClosedTable();
    int choice;

    while (true) {
        cout << "\n=== МЕНЮ ЗАКРИТОЇ ХЕШ-ТАБЛИЦІ ===\n";
        cout << "1. Додати новий товар\n";
        cout << "2. Видалити товар\n";
        cout << "3. Редагувати товар\n";
        cout << "4. Знайти товари за магазином\n";
        cout << "5. Знайти товари за діапазоном вартості\n";
        cout << "0. Вийти\n";
        cout << "Оберіть дію: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n');

        switch (choice) {
        case 1: {
            Product p;
            p.name = getValidString("Введіть назву товару: ");
            p.store = getValidString("Введіть назву магазину: ");
            p.price = getValidDouble("Введіть вартість (грн): ");
            p.quantity = getValidDouble("Введіть кількість: ");
            p.unit = getValidString("Введіть одиницю вимірювання: ");

            if (insertClosedHash(myTable, p)) cout << "Товар додано!\n";
            else cout << "Помилка: Товар вже існує або таблиця заповнена.\n";
            break;
        }
        case 2: {
            string name = getValidString("Введіть назву товару для видалення: ");
            if (removeClosedHash(myTable, name)) cout << "Товар видалено!\n";
            else cout << "Товар не знайдено.\n";
            break;
        }
        case 3: {
            string name = getValidString("Введіть назву товару для редагування: ");
            Product* p = searchClosedHash(myTable, name);
            if (p) {
                p->store = getValidString("Новий магазин: ");
                p->price = getValidDouble("Нова вартість: ");
                p->quantity = getValidDouble("Нова кількість: ");
                p->unit = getValidString("Нова одиниця вимірювання: ");
                cout << "Дані оновлено!\n";
            }
            else cout << "Товар не знайдено.\n";
            break;
        }
        case 4: {
            string store = getValidString("Введіть назву магазину: ");
            vector<Product> found = getProductsByStoreClosed(myTable, store);
            printProductList(found);
            break;
        }
        case 5: {
            double minP = getValidDouble("Мінімальна ціна: ");
            double maxP = getValidDouble("Максимальна ціна: ");
            if (minP > maxP) swap(minP, maxP);
            vector<Product> found = getProductsByPriceClosed(myTable, minP, maxP);
            printProductList(found);
            break;
        }
        case 0:
            cout << "Завершення роботи.\n";
            return 0;
        default:
            cout << "Невірний пункт меню.\n";
        }
    }
}