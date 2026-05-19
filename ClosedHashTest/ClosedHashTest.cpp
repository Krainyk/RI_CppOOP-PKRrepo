#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include "../lab3.13.2/Product.h"
#include "../lab3.13.2/ClosedHash.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ClosedHashTests
{
    TEST_CLASS(ClosedHashTests)
    {
    public:

        TEST_METHOD(TestInsertAndSearch)
        {
            ClosedHashTable table = createClosedTable();
            Product p1 = { "Молоко", "АТБ", 35.5, 10, "пляшка" };
            Product p2 = { "Хліб", "Сільпо", 20.0, 5, "буханець" };

            bool isInserted1 = insertClosedHash(table, p1);
            bool isInserted2 = insertClosedHash(table, p2);
            bool isDuplicateInserted = insertClosedHash(table, p1);

            Product* foundProduct = searchClosedHash(table, "Молоко");
            Product* notFoundProduct = searchClosedHash(table, "М'ясо");

            Assert::IsTrue(isInserted1);
            Assert::IsTrue(isInserted2);
            Assert::IsFalse(isDuplicateInserted);

            Assert::IsNotNull(foundProduct);
            Assert::AreEqual(string("АТБ"), foundProduct->store);
            Assert::AreEqual(35.5, foundProduct->price);

            Assert::IsNull(notFoundProduct);
        }

        TEST_METHOD(TestRemove)
        {
            ClosedHashTable table = createClosedTable();
            Product p1 = { "Сир", "Фора", 50.0, 2, "упаковка" };
            Product p2 = { "Кефір", "Фора", 30.0, 3, "пляшка" };

            insertClosedHash(table, p1);
            insertClosedHash(table, p2);

            Assert::IsTrue(removeClosedHash(table, "Сир"));

            Assert::IsNull(searchClosedHash(table, "Сир"));

            Assert::IsNotNull(searchClosedHash(table, "Кефір"));

            Assert::IsFalse(removeClosedHash(table, "Сир"));

            Assert::IsFalse(removeClosedHash(table, "Масло"));
        }
    };
}