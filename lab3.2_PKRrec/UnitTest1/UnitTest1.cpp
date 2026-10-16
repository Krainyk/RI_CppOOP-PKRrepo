#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab3.2_PKRrec/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TesthasDuplicates)
		{
			Node* head = NULL;
			addNode(head, 1);
			addNode(head, 2);
			addNode(head, 3);
			addNode(head, 4);
			Assert::IsFalse(hasDuplicates(head));
			addNode(head, 2);
			Assert::IsTrue(hasDuplicates(head));
		}
	};
}
