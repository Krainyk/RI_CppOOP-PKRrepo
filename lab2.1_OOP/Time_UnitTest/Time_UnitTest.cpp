#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.1/Time.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TimeTest
{
    TEST_CLASS(TimeTest)
    {
    public:

        TEST_METHOD(TestInitAndGetters)
        {
            Time t(2, 30);

            Assert::AreEqual(2, t.GetHours());
            Assert::AreEqual(30, t.GetMinutes());
        }

        TEST_METHOD(TestMinutes)
        {
            Time t(1, 30);

            Assert::AreEqual(90, t.minutes());
        }

        TEST_METHOD(TestIncrement)
        {
            Time t(2, 30);

            ++t; // години
            Assert::AreEqual(3, t.GetHours());

            t++; // хвилини
            Assert::AreEqual(31, t.GetMinutes());
        }

        TEST_METHOD(TestAssignment)
        {
            Time t1(5, 45);
            Time t2;

            t2 = t1;

            Assert::AreEqual(5, t2.GetHours());
            Assert::AreEqual(45, t2.GetMinutes());
        }

        TEST_METHOD(TestMakeTime)
        {
            Time t = makeTime(3, 15);

            Assert::AreEqual(3, t.GetHours());
            Assert::AreEqual(15, t.GetMinutes());
        }
    };
}