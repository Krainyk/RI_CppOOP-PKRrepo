#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.3C/BitString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BitStringTest
{
    TEST_CLASS(BitStringTest)
    {
    public:

        TEST_METHOD(TestInit)
        {
            BitString b(5, 3);

            Assert::AreEqual((long)5, b.getFirstPart());
            Assert::AreEqual((long)3, b.getSecondPart());
        }

        TEST_METHOD(TestAnd)
        {
            BitString b1(5, 3); // 0101 & 0011 = 0001
            BitString b2(3, 1);

            BitString res = b1 & b2;

            Assert::AreEqual((long)(5 & 3), res.getFirstPart());
        }

        TEST_METHOD(TestIncrement)
        {
            BitString b(1, 1);

            ++b;

            Assert::AreEqual((long)2, b.getFirstPart());
        }

        TEST_METHOD(TestObjectCount)
        {
            int before = Object::getCount();

            BitString b1;
            BitString b2;

            Assert::AreEqual(before + 2, Object::getCount());
        }
    };
}