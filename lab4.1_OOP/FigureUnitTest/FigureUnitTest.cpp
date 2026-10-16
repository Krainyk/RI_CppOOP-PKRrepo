#include "pch.h"
#include "CppUnitTest.h"
#include "../lab4.1_OOP/Figure.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestFigure
{
	TEST_CLASS(UnitTestFigure)
	{
	public:

		TEST_METHOD(TestParallelepiped)
		{
			Parallelepiped p(2, 3, 4);
			Assert::AreEqual(24.0, p.volume());
		}

		TEST_METHOD(TestPyramid)
		{
			Pyramid p(3, 4, 6);
			Assert::AreEqual(24.0, p.volume());
		}
	};
}