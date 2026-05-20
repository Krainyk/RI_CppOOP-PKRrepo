#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.3Iter/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListTests
{
    TEST_CLASS(ListTests)
    {
    public:

        TEST_METHOD(TestAppend)
        {
            Node* head = nullptr;
            head = appendNode(head, 10);
            head = appendNode(head, 20);

            Assert::IsNotNull(head);
            Assert::AreEqual(10, head->data);
            Assert::IsNotNull(head->next);
            Assert::AreEqual(20, head->next->data);
            Assert::IsTrue(head->next->prev == head);

            destroyList(head);
        }

        TEST_METHOD(TestDeletePreceding_Middle)
        {
            Node* head = nullptr;
            head = appendNode(head, 10);
            head = appendNode(head, 20);
            head = appendNode(head, 30);
            head = appendNode(head, 40);

            head = deletePrecedingNodes(head, 30);

            Assert::AreEqual(10, head->data);
            Assert::AreEqual(30, head->next->data);
            Assert::AreEqual(40, head->next->next->data);

            Assert::IsTrue(head->next->prev == head); // 30->prev == 10

            destroyList(head);
        }

        TEST_METHOD(TestDeletePreceding_Head)
        {
            Node* head = nullptr;
            head = appendNode(head, 10);
            head = appendNode(head, 20);
            head = appendNode(head, 30);

            head = deletePrecedingNodes(head, 20);

            Assert::AreEqual(20, head->data);
            Assert::IsNull(head->prev);
            Assert::AreEqual(30, head->next->data);

            destroyList(head);
        }

        TEST_METHOD(TestDeletePreceding_NothingToDelete)
        {
            Node* head = nullptr;
            head = appendNode(head, 10);
            head = appendNode(head, 20);

            head = deletePrecedingNodes(head, 10);

            Assert::AreEqual(10, head->data);
            Assert::AreEqual(20, head->next->data);

            destroyList(head);
        }
    };
}