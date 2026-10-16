#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.4Iter/CircularList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircularListTests
{
    TEST_CLASS(CircularListTests)
    {
    public:

        TEST_METHOD(TestAppendCircularLink)
        {
            Node* head = nullptr;
            head = appendNode(head, 10);

            Assert::IsNotNull(head);
            Assert::IsTrue(head->next == head);

            head = appendNode(head, 20);
            head = appendNode(head, 30);

            Assert::IsTrue(head->next->next->next == head);

            destroyList(head);
        }

        TEST_METHOD(TestCountOdd_MixedNumbers)
        {
            Node* head = nullptr;
            head = appendNode(head, 10);
            head = appendNode(head, 3);
            head = appendNode(head, -5);
            head = appendNode(head, 8);
            head = appendNode(head, 7);

            int result = countOddElements(head);

            Assert::AreEqual(3, result);

            destroyList(head);
        }

        TEST_METHOD(TestCountOdd_EmptyList)
        {
            Node* head = nullptr;
            int result = countOddElements(head);
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(TestCountOdd_AllEven)
        {
            Node* head = nullptr;
            head = appendNode(head, 2);
            head = appendNode(head, 4);
            head = appendNode(head, 6);

            int result = countOddElements(head);
            Assert::AreEqual(0, result);

            destroyList(head);
        }
    };
}