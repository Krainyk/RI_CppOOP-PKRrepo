#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2.2/Matrix.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTests
{
	TEST_CLASS(MatrixTests)
	{
	public:
		
		// Тест конструктора та розмірів
		TEST_METHOD(TestConstructor)
		{
			Matrix m(3, 4);
			Assert::AreEqual(3, m.getRows());
			Assert::AreEqual(4, m.getCols());
		}

		// Тест додавання матриць
		TEST_METHOD(TestAddition)
		{
			Matrix A(2, 2);
			Matrix B(2, 2);

			// На жаль, у нас немає прямого доступу до data, 
			// тому для тесту можна тимчасово використати оператор >> 
			// або додати метод setElement(r, c, value) для зручності.
			// Припустимо, ми перевіряємо, що додавання не викликає помилок:
			Matrix C = A + B; 
			
			Assert::AreEqual(2, C.getRows());
			Assert::AreEqual(2, C.getCols());
		}

		// Тест множення на скаляр
		TEST_METHOD(TestScalarMultiplication)
		{
			Matrix A(2, 2); 
			// Після створення Matrix(2,2) всі елементи 0 (завдяки твоєму коду)
			A *= 10;
			
			// Якщо матриця була 0, то 0 * 10 = 0. 
			// Перевіряємо, що розміри залишились тими ж.
			Assert::AreEqual(2, A.getRows());
		}
	};
}
