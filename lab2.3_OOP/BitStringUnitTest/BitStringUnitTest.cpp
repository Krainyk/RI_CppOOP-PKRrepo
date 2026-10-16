#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.3_OOP/BitString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BitStringTest
{
    TEST_CLASS(BitStringTest)
    {
    public:

        TEST_METHOD(TestAnd)
        {
            BitString b1(5, 10);
            BitString b2(3, 12);

            BitString res = b1 & b2;

            Assert::AreEqual((long)(5 & 3), res.getFirstPart());
            Assert::AreEqual((long)(10 & 12), res.getSecondPart());
        }

        TEST_METHOD(TestOr)
        {
            BitString b1(5, 10);
            BitString b2(3, 12);

            BitString res = b1 | b2;

            Assert::AreEqual((long)(5 | 3), res.getFirstPart());
            Assert::AreEqual((long)(10 | 12), res.getSecondPart());
        }

        TEST_METHOD(TestNot)
        {
            BitString b1(5, 10);

            BitString res = ~b1;

            Assert::AreEqual((long)((~5) & 0xFF), res.getFirstPart());
            Assert::AreEqual((long)((~10) & 0xFF), res.getSecondPart());
        }

        TEST_METHOD(TestIncrement)
        {
            BitString b1(5, 10);

            ++b1;

            Assert::AreEqual((long)((5 << 1) & 0xFF), b1.getFirstPart());
            Assert::AreEqual((long)((10 << 1) & 0xFF), b1.getSecondPart());
        }

        TEST_METHOD(TestDecrement)
        {
            BitString b1(5, 10);

            --b1;

            Assert::AreEqual((long)(5 >> 1), b1.getFirstPart());
            Assert::AreEqual((long)(10 >> 1), b1.getSecondPart());
        }

        TEST_METHOD(TestAssignment)
        {
            BitString b1(7, 9);
            BitString b2;

            b2 = b1;

            Assert::AreEqual(b1.getFirstPart(), b2.getFirstPart());
            Assert::AreEqual(b1.getSecondPart(), b2.getSecondPart());
        }

        TEST_METHOD(TestToString)
        {
            BitString b1(1, 2);

            std::string s = (std::string)b1;

            Assert::IsTrue(s.length() > 0);
        }
    };
}