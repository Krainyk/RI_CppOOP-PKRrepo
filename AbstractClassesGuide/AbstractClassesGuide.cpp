#include <iostream>
#include <string>
using namespace std;

// Task 1: Створити абстрактний клас "Зброя" з чистою віртуальною функцією "атака()". Потім створити два похідні класи: "Меч" та "Арбалет", які реалізують функцію атаки по-своєму.
class Weapon {
protected:
	string name;
	int damage;

public:
	Weapon(string n, int dmg) : name(n), damage(dmg) {}	
	virtual void attack() = 0;
	virtual ~Weapon() {}
};

class Sword : public Weapon {
public:
	Sword(string n, int dmg) : Weapon(n, dmg) {}
	void attack() override {
		cout << "Swinging the " << name << " for " << damage << " damage!" << endl;
	}
};

class Crossbow : public Weapon {
protected:
	int arrows;

public:
	Crossbow(string n, int dmg, int ar) : Weapon(n, dmg), arrows(ar) {}
	void attack() override {
		if (arrows > 0) {
			cout << "Shooting an arrow from the " << name << " for " << damage << " damage!" << endl;
			arrows--;
		} else {
			cout << "No arrows left in the " << name << "!" << endl;
		}
	}
};

int main() {
	Sword mySword("Arrondit", 50);
	Crossbow myCrossbow("Crossbow Geralt of Rivia", 40, 1);

	mySword.attack();
	myCrossbow.attack();
	myCrossbow.attack(); // Attempting to attack with no arrows left
}