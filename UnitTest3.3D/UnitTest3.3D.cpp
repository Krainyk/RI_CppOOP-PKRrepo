#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.3E/Pair.h"
#include "../lab3.3E/RightAngled.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(PairTests)
    {
    public:

        TEST_METHOD(TestProduct)
        {
            Pair p(3, 4);
            Assert::AreEqual(12.0, p.product());
        }

        TEST_METHOD(TestRightAngledArea)
        {
            RightAngled t(3, 4);
            Assert::AreEqual(6.0, t.area());
        }

        TEST_METHOD(TestHypotenuse)
        {
            RightAngled t(3, 4);
            Assert::AreEqual(5.0, t.hypotenuse());
        }
    };
}