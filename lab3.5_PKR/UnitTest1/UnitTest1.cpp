#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.5.PKR/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestprocessExpression)
		{
			std::string expr = "3 + 4 * (2 - 1)";
			processExpression(expr);
		}
	};
}
