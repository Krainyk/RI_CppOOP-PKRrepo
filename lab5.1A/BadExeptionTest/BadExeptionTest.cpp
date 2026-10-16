#include "pch.h"
#include "CppUnitTest.h"

#include "../lab5.1A/Time.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TimeTests
{
    TEST_CLASS(TimeClassTests)
    {
    public:

        TEST_METHOD(MinutesTest)
        {
            Time t(2, 30);

            Assert::AreEqual(150, t.minutes());
        }

        TEST_METHOD(IncrementTest)
        {
            Time t(1, 59);

            ++t;

            Assert::AreEqual(2, t.GetHours());
            Assert::AreEqual(0, t.GetMinutes());
        }

        TEST_METHOD(DecrementTest)
        {
            Time t(2, 0);

            --t;

            Assert::AreEqual(1, t.GetHours());
            Assert::AreEqual(59, t.GetMinutes());
        }

        TEST_METHOD(ConstructorExceptionTest)
        {
            Assert::ExpectException<invalid_argument>([] {
                Time t(-1, 70);
                });
        }

        TEST_METHOD(MakeTimeExceptionTest)
        {
            Assert::ExpectException<invalid_argument>([] {
                makeTime(3, 90);
                });
        }
    };
}