#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab3.2_PKR/Header.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Testhasduplicates)
		{
			Node* head = NULL;
			addNode(head, 10);
			addNode(head, 20);
			addNode(head, 30);
			addNode(head, 50);
			addNode(head, 20);
			Assert::IsTrue(hasDuplicates(head));
		}
	};
}
