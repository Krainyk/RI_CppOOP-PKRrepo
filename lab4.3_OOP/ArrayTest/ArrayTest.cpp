#include "pch.h"
#include "CppUnitTest.h"

#include "../lab4.3_OOP/Hex.h"
#include "../lab4.3_OOP/Money.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayTest
{
	TEST_CLASS(ArrayTest)
	{
	public:

		TEST_METHOD(TestHexPlus)
		{
			Hex h1;
			Hex h2;

			h1.fromDecimal(10);
			h2.fromDecimal(5);

			Hex result = h1 + h2;

			Assert::AreEqual(
				(unsigned long long)15,
				result.toDecimal()
			);
		}

		TEST_METHOD(TestHexMinus)
		{
			Hex h1;
			Hex h2;

			h1.fromDecimal(20);
			h2.fromDecimal(5);

			Hex result = h1 - h2;

			Assert::AreEqual(
				(unsigned long long)15,
				result.toDecimal()
			);
		}

		TEST_METHOD(TestHexCompare)
		{
			Hex h1;
			Hex h2;

			h1.fromDecimal(30);
			h2.fromDecimal(10);

			Assert::IsTrue(h2 < h1);
		}

		TEST_METHOD(TestMoneyPlus)
		{
			Money m1;
			Money m2;

			m1.fromNumber(1050);
			m2.fromNumber(250);

			Money result = m1 + m2;

			Assert::AreEqual(
				(long long)1300,
				result.toNumber()
			);
		}

		TEST_METHOD(TestMoneyMinus)
		{
			Money m1;
			Money m2;

			m1.fromNumber(2000);
			m2.fromNumber(500);

			Money result = m1 - m2;

			Assert::AreEqual(
				(long long)1500,
				result.toNumber()
			);
		}

		TEST_METHOD(TestMoneyCompare)
		{
			Money m1;
			Money m2;

			m1.fromNumber(3000);
			m2.fromNumber(1000);

			Assert::IsTrue(m2 < m1);
		}
	};
}