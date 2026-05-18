#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.3G/Object.h"
#include "../lab3.3G/Point.h"
#include "../lab3.3G/Triangle.h"

#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests
{
    TEST_CLASS(ObjectTests)
    {
    public:

        TEST_METHOD(ObjectCounterTest)
        {
            int start = Object::getCount();

            Point p1(1, 2);
            Point p2(3, 4);

            int after = Object::getCount();

            Assert::IsTrue(after == start + 2);
        }
    };

    TEST_CLASS(PointTests)
    {
    public:

        TEST_METHOD(DistanceTest)
        {
            Point A(0, 0);
            Point B(3, 4);

            Assert::AreEqual(5.0, A.distanceTo(B));
        }

        TEST_METHOD(MoveTest)
        {
            Point A(1, 1);
            A.moveX(2);
            A.moveY(3);

            Assert::AreEqual(3.0, A.getX());
            Assert::AreEqual(4.0, A.getY());
        }
    };

    TEST_CLASS(TriangleTests)
    {
    public:

        TEST_METHOD(PerimeterTest)
        {
            Point A(0, 0), B(4, 0), C(0, 3);

            Triangle t;
            t.Init(A, B, C);

            Assert::AreEqual(12.0, t.perimeter());
        }

        TEST_METHOD(AreaTest)
        {
            Point A(0, 0), B(4, 0), C(0, 3);

            Triangle t;
            t.Init(A, B, C);

            Assert::AreEqual(6.0, t.area());
        }

        TEST_METHOD(TypeTest)
        {
            Point A(0, 0), B(4, 0), C(0, 3);

            Triangle t;
            t.Init(A, B, C);

            // ןנמסעמ ןונוג³נÿ÷למ שמ םו ןאהא÷
            t.type();
        }
    };
}