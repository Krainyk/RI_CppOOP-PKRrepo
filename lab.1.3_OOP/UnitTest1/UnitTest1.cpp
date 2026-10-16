#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab.1.3/BitString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_Not)
		{
			BitString b1, result;
			b1.Init(2, 3);

			result = b1.Not();

			Assert::AreEqual(-3L, result.getfirstPart());
			Assert::AreEqual(-4L, result.getsecondPart());
		}
	};
}
