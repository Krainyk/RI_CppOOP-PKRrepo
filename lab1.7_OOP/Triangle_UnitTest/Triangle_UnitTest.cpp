#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1.7_OOP/Triangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleTest
{
    TEST_CLASS(TriangleTest)
    {
    public:

        TEST_METHOD(TestTriangleBasic)
        {
            Point A, B, C;
            A.Init(0, 0);
            B.Init(3, 0);
            C.Init(0, 4);

            Triangle t;
            t.Init(A, B, C);

            Assert::AreEqual(5.0, t.get_a(), 0.001);
            Assert::AreEqual(4.0, t.get_b(), 0.001);
            Assert::AreEqual(3.0, t.get_c(), 0.001);

            Assert::AreEqual(6.0, t.area(), 0.001);

            Assert::AreEqual(12.0, t.perimeter(), 0.001);
        }

        TEST_METHOD(TestTriangleHeights)
        {
            Point A, B, C;
            A.Init(0, 0);
            B.Init(3, 0);
            C.Init(0, 4);

            Triangle t;
            t.Init(A, B, C);

            Assert::AreEqual(2.4, t.heightA(), 0.01);
            Assert::AreEqual(3.0, t.heightB(), 0.01);
            Assert::AreEqual(4.0, t.heightC(), 0.01);
        }

        TEST_METHOD(TestPointDistance)
        {
            Point A, B;
            A.Init(0, 0);
            B.Init(3, 4);

            Assert::AreEqual(5.0, A.distanceTo(B), 0.001);
        }
    };
}
