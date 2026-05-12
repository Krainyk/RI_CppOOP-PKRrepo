#include "pch.h"
#include "CppUnitTest.h"
#include "..//3.13.1_PRK/Product.h"
#include "..//3.13.1_PRK/Trie.h"
#include <string>
#include <unordered_map>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TrieTests
{
    TEST_CLASS(TrieTests)
    {
    public:

        TEST_METHOD(TestInsertAndSearch)
        {
            TrieNode* root = createTrie();
            Product p1 = { "Молоко", "АТБ", 35.5, 10, "пляшка" };
            Product p2 = { "Хліб", "Сільпо", 20.0, 5, "буханець" };

            bool isInserted1 = insertTrie(root, p1);
            bool isInserted2 = insertTrie(root, p2);
            bool isDuplicateInserted = insertTrie(root, p1);

            Product* foundProduct = searchTrie(root, "Молоко");
            Product* notFoundProduct = searchTrie(root, "М'ясо");

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
            // Arrange
            TrieNode* root = createTrie();
            Product p1 = { "Сир", "Фора", 50.0, 2, "упаковка" };
            insertTrie(root, p1);

            // Act & Assert
            // 1. Успішне видалення
            Assert::IsTrue(removeTrie(root, "Сир"));

            // 2. Пошук після видалення має повернути nullptr
            Assert::IsNull(searchTrie(root, "Сир"));

            // 3. Повторне видалення має повернути false
            Assert::IsFalse(removeTrie(root, "Сир"));

            // 4. Видалення неіснуючого товару
            Assert::IsFalse(removeTrie(root, "Кефір"));
        }
    };
}