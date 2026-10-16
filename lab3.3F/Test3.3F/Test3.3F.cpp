#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.3F/Point.h"
#include "../lab3.3F/TrianglePublic.h"
#include "../lab3.3F/TrianglePrivate.h"

#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GeometryTests
{
    TEST_CLASS(PointTests)
    {
    public:

        TEST_METHOD(DistanceTest)
        {
            Point A, B;
            A.Init(0, 0);
            B.Init(3, 4);

            Assert::AreEqual(5.0, A.distanceTo(B));
        }
    };

    TEST_CLASS(TrianglePublicTests)
    {
    public:

        TEST_METHOD(PerimeterTest)
        {
            Point A, B, C;
            A.Init(0, 0);
            B.Init(4, 0);
            C.Init(0, 3);

            TrianglePublic t;
            t.Init(A, B, C);

            Assert::AreEqual(12.0, t.perimeter());
        }

        TEST_METHOD(AreaTest)
        {
            Point A, B, C;
            A.Init(0, 0);
            B.Init(4, 0);
            C.Init(0, 3);

            TrianglePublic t;
            t.Init(A, B, C);

            Assert::AreEqual(6.0, t.area());
        }
    };

    TEST_CLASS(TrianglePrivateTests)
    {
    public:

        TEST_METHOD(PerimeterTest)
        {
            Point A, B, C;
            A.Init(0, 0);
            B.Init(4, 0);
            C.Init(0, 3);

            TrianglePrivate t;
            t.Init(A, B, C);

            Assert::AreEqual(12.0, t.perimeter());
        }

        TEST_METHOD(AreaTest)
        {
            Point A, B, C;
            A.Init(0, 0);
            B.Init(4, 0);
            C.Init(0, 3);

            TrianglePrivate t;
            t.Init(A, B, C);

            Assert::AreEqual(6.0, t.area());
        }
    };
}