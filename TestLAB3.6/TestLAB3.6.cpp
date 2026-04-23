#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.6/D3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MultiInheritanceTest
{
    TEST_CLASS(MultiInheritanceTest)
    {
    public:

        TEST_METHOD(TestConstructors)
        {
            D3 obj(1, 10, 2, 20, 30);

            // просто перевірка, що об'єкт створився
            Assert::IsTrue(true);
        }

        TEST_METHOD(TestSizes)
        {
            B1 b1(1);
            B2 b2(2);
            D1 d1(1, 10);
            D2 d2(1, 10, 2, 20);
            D3 d3(1, 10, 2, 20, 30);

            Assert::IsTrue(sizeof(d1) >= sizeof(b1));
            Assert::IsTrue(sizeof(d2) >= sizeof(d1));
            Assert::IsTrue(sizeof(d3) >= sizeof(d2));
        }

        TEST_METHOD(TestShow)
        {
            D3 obj(1, 10, 2, 20, 30);

            // перевірка, що show() не падає
            obj.show();

            Assert::IsTrue(true);
        }

        TEST_METHOD(TestHierarchy)
        {
            D3 obj(1, 10, 2, 20, 30);

            // перевіряємо, що об'єкт існує і тип правильний
            D2* basePtr = &obj;

            Assert::IsNotNull(basePtr);
        }
    };
}