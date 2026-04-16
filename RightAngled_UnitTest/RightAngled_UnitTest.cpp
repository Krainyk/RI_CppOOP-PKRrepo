#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.1/RightAngled.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleTests
{
    TEST_CLASS(TriangleTests)
    {
    public:

        // Перевіряємо базовий клас Pair
        TEST_METHOD(TestPairProduct)
        {
            Pair p(3.0, 4.0);
            // Очікуємо 12.0 (3 * 4)
            Assert::AreEqual(12.0, p.product());
        }

        // Перевіряємо розрахунок гіпотенузи в RightAngled
        TEST_METHOD(TestRightAngledHypotenuse)
        {
            // Єгипетський трикутник (катети 3 і 4, гіпотенуза має бути 5)
            RightAngled t(3.0, 4.0);
            Assert::AreEqual(5.0, t.hypotenuse());
        }

        // Перевіряємо розрахунок площі в RightAngled
        TEST_METHOD(TestRightAngledArea)
        {
            // Площа: (3 * 4) / 2 = 6
            RightAngled t(3.0, 4.0);
            Assert::AreEqual(6.0, t.area());
        }

        // Перевіряємо, чи працюють геттери після створення об'єкта
        TEST_METHOD(TestConstructorsAndGetters)
        {
            RightAngled t(6.0, 8.0);
            Assert::AreEqual(6.0, t.getFirst());
            Assert::AreEqual(8.0, t.getSecond());
        }
    };
}
