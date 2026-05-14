#include <iostream>
using namespace std;
/* Task 1: Базовий клас А має protected int data та конструктор, який ініціалізує це поле. Клас B наслідує A і має своє власне поле data та конструктор, який ініціалізує обидва поля. Клас C наслідує B і має своє власне поле data та конструктор, який ініціалізує всі три поля. Реалізуйте метод show() для кожного класу, який виводить відповідне поле data. У main() створіть об'єкт класу C та викличте метод show() для кожного класу, щоб продемонструвати успадкування та доступ до полів.
class A {
protected:
	int data;

public:
	A(int a) : data(a) {}

	void show() { cout << "Data A: " << data << endl; }
};

class B : public A {
protected:
	int data;

public:
	B(int a, int b) : A(a), data(b) {}

	void show() { cout << "Data B: " << data << endl; }
};

class C : public B {
protected:
	int data;

public:
	C(int a, int b, int c) : B(a, b), data(c) {}

	void show() { cout << "Data C: " << data << endl; }
};
*/
/* Task 2: У цьому завданні ми розглянемо множинне наслідування. Створіть два базові класи A та B, кожен з яких має своє власне поле data та конструктор для його ініціалізації. Клас C наслідує обидва класи A та B і має своє власне поле data та конструктор, який ініціалізує всі три поля. Реалізуйте метод show() для кожного класу, який виводить відповідне поле data. У main() створіть об'єкт класу C та викличте метод show() для кожного класу, щоб продемонструвати множинне наслідування та доступ до полів.
class A {
protected:
	int data;

public:
	A(int a) : data(a) {}
	void show() { cout << "Data A: " << data << endl; }
};

class B {
protected:
	int data;

public:
	B(int b) : data(b) {}
	void show() { cout << "Data B: " << data << endl; }
};

class C : public A, public B {
protected:
	int data;

public:
	C(int a, int b, int c) : A(a), B(b), data(c) {}
	void show() { cout << "Data C: " << data << endl; }
};
*/

/* Task 3: У цьому завданні ми розглянемо віртуальне наслідування. Створіть базовий клас A з полем data та конструктором для його ініціалізації. Клас B наслідує A віртуально та має своє власне поле data та конструктор, який ініціалізує обидва поля. Клас C також наслідує A віртуально та має своє власне поле data та конструктор, який ініціалізує обидва поля. Клас D наслідує як B, так і C, і має своє власне поле data та конструктор, який ініціалізує всі три поля. Реалізуйте метод show() для кожного класу, який виводить відповідне поле data. У main() створіть об'єкт класу D та викличте метод show() для кожного класу, щоб продемонструвати віртуальне наслідування та доступ до полів.
class A {
protected:
	int data;

public:
	A(int a) : data(a) {}
	void show() { cout << "Data A: " << data << endl; }
};

class B : virtual public A {
protected:
	int data;

public:
	B(int a, int b) : A(a), data(b) {}
	void show() { cout << "Data B: " << data << endl; }
};

class C : virtual public A {
protected:
	int data;

public:
	C(int a, int c) : A(a), data(c) {}
	void show() { cout << "Data C: " << data << endl; }
};

class D : virtual public A, public C {
protected:
	int data;

public:
	D(int a, int c, int d) : A(a), C(a, c), data(d) {}
	void show() { cout << "Data D: " << data << endl; }
};
*/
// Task 4: У цьому завданні ми розглянемо віртуальне наслідування з множинним наслідуванням. Створіть базовий клас A з полем data та конструктором для його ініціалізації. Клас B наслідує A віртуально та має своє власне поле data та конструктор, який ініціалізує обидва поля. Клас C також наслідує A віртуально та має своє власне поле data та конструктор, який ініціалізує обидва поля. Клас D наслідує як B, так і C, і має своє власне поле data та конструктор, який ініціалізує всі три поля. Реалізуйте метод show() для кожного класу, який виводить відповідне поле data. У main() створіть об'єкт класу D та викличте метод show() для кожного класу, щоб продемонструвати віртуальне наслідування з множинним наслідуванням та доступ до полів.
class A {
protected:
	int data;

public:
	A(int a) : data(a) {}
	void show() { cout << "Data A: " << data << endl; }
};

class B : virtual public A {
protected:
	int data;

public:
	B(int a, int b) : A(a), data(b) {}
	void show() { cout << "Data B: " << data << endl; }
};

class C : virtual public A {
protected:
	int data;

public:
	C(int a, int c) : A(a), data(c) {}
	void show() { cout << "Data C: " << data << endl; }
};

class D : public B, public C {
protected:
	int data;

public:
	D(int a, int b, int c, int d) : A(a), B(a, b), C(a, c), data(d) {}
	void show() { cout << "Data D: " << data << endl; }
};
int main() {
	/* Task 1:
	C c1(1, 3, 4);
	c1.show();
	c1.B::show();
	c1.A::show();*/


	/* Task 2:
	A obja(1);
	obja.show();

	B objb(2);
	objb.show();

	C objc(3, 4, 5);
	objc.show();

	objc.A::show();
	objc.B::show();*/

	/* Task 3:
	D objd(6, 7, 8);
	objd.show();
	objd.A::show();
	objd.C::show();

	B objb(9, 10);
	objb.show();
	objb.A::show();
	*/

	D objd(6, 7, 8, 9);
	objd.show();
	objd.A::show();
	objd.B::show();
	objd.C::show();
}