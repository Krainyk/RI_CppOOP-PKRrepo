#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1.6_OOP/RightAngled.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Rectacgeltest
{
    TEST_CLASS(Rectacgeltest)
    {
    public:

        TEST_METHOD(TestHypotenuse)
        {
            RightAngled t;
            t.Init(3, 4);

            Assert::AreEqual(5.0, t.hypotenuse());
        }

        TEST_METHOD(TestArea)
        {
            RightAngled t;
            t.Init(3, 4);

            Assert::AreEqual(6.0, t.area());
        }
    };
}