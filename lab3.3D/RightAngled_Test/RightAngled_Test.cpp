#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.3D/RightAngled.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRightAngled
{
    TEST_CLASS(UnitTestRightAngled)
    {
    public:

        TEST_METHOD(TestArea)
        {
            RightAngled t(3, 4);

            Assert::AreEqual(6.0, t.area());
        }

        TEST_METHOD(TestHypotenuse)
        {
            RightAngled t(3, 4);

            Assert::AreEqual(5.0, t.hypotenuse());
        }

        TEST_METHOD(TestProduct)
        {
            Pair p(2, 5);

            Assert::AreEqual(10.0, p.product());
        }

        TEST_METHOD(TestSetters)
        {
            Pair p;

            p.setFirst(7);
            p.setSecond(8);

            Assert::AreEqual(7.0, p.getFirst());
            Assert::AreEqual(8.0, p.getSecond());
        }
    };
}