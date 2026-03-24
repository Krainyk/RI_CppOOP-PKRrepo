#include "Header.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "--- Тестування функції makeVector ---\n";
    Vector v1 = makeVector(3);

    cout << "Заповнюємо масив:\n";
    v1.setElement(0, 3);
    v1.setElement(1, 4);
    v1.setElement(2, 0);
    v1.Display();

    cout << "Евклідова норма: " << v1.getNorm() << "\n\n";

    cout << "--- Тестування помилок (вихід за межі) ---\n";
    v1.setElement(5, 99);
    cout << "Поточний стан (має бути 2): " << v1.getState() << "\n\n";

    cout << "--- Тестування введення з клавіатури ---\n";
    Vector v2;
    v2.Read();
    v2.Display();
    cout << "Евклідова норма: " << v2.getNorm() << "\n\n";

    
    // Щоб перевірити екстрене завершення, розкоментуйте цей рядок:
    //Vector v3 = makeVector(-5);

    return 0;
}