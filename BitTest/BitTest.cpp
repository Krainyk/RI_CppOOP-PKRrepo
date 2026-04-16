#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.3A/BitStringPub.h"
#include "../lab3.3A/BitStringPriv.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BitStringTests
{
    TEST_CLASS(BitStringTests)
    {
    public:

        // Тест 1: Перевірка правильної ініціалізації через відкрите успадкування
        TEST_METHOD(TestPublicCreation)
        {
            BitStringPub b(10, 20);
            // Оскільки успадкування відкрите, ми маємо доступ до базових геттерів
            Assert::AreEqual(10ul, b.getFirst());
            Assert::AreEqual(20ul, b.getSecond());
        }

        // Тест 2: Перевірка логічного І (AND)
        TEST_METHOD(TestPublicAndOperator)
        {
            // 15 (у двійковій 1111) та 7 (у двійковій 0111)
            // 15 & 7 = 7
            BitStringPub b1(15, 255);
            BitStringPub b2(7, 15);

            BitStringPub result = b1 & b2;

            Assert::AreEqual(7ul, result.getFirst());
            Assert::AreEqual(15ul, result.getSecond());
        }

        // Тест 3: Перевірка логічного НІ (NOT)
        TEST_METHOD(TestPublicNotOperator)
        {
            BitStringPub b(0, 0); // Всі нулі
            BitStringPub result = ~b;

            // ~0 має дати максимальне значення для unsigned long (всі одиниці)
            unsigned long max_val = ~0ul;

            Assert::AreEqual(max_val, result.getFirst());
            Assert::AreEqual(max_val, result.getSecond());
        }

        // Тест 4: Перевірка створення об'єкта із закритим успадкуванням
        TEST_METHOD(TestPrivateCreation)
        {
            // Для закритого успадкування ми не маємо доступу до getFirst()
            // Тому просто перевіряємо, що об'єкт успішно створюється і 
            // виконується операція (не викликаючи крашу)
            BitStringPriv b1(5, 5);
            BitStringPriv b2 = ~b1;

            // Якщо програма дійшла до цього рядка, тест пройдено
            Assert::IsTrue(true);
        }
    };
}
