#include <iostream>
#include <windows.h>
using namespace std;

class AlchemWitcher {
protected:
	int toxicityLevel = 0;

public:
	AlchemWitcher() : toxicityLevel(0) {}

	virtual void drinkPotion() {
		int Lastivka = 25;
		toxicityLevel += Lastivka;
		cout << "Відьмак алхімік випив ластівку, шкала токсичності: +" << toxicityLevel << endl;
	}
};

class SignWitcher : public AlchemWitcher {
public:
	SignWitcher() : AlchemWitcher() {}

	void drinkPotion() override {
		int LisMaribor = 20;
		toxicityLevel += LisMaribor;
		cout << "Відьмак маг випив ліс марібор, шкала токсичності: +" << toxicityLevel << endl;
	}
};

class SwordWitcher : public AlchemWitcher {
public:
	SwordWitcher() : AlchemWitcher() {}

	using AlchemWitcher::drinkPotion;

	void drinkPotion(bool bribePotion) {
		int commonPotion = 15;
		toxicityLevel += commonPotion;

		if (bribePotion) {
			cout << "Відьмак мечник випив підкупне зілля тому, шкала токсичності не змінилася: " << toxicityLevel << endl;
		}
		else {
			cout << "Відьмак мечник випив звичайне зілля, шкала токсичності: +" << toxicityLevel << endl;
		}
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	AlchemWitcher alchemWitcher;
	SignWitcher signWitcher;
	SwordWitcher swordWitcher;

	AlchemWitcher* witcherPtr;

	witcherPtr = &alchemWitcher;
	witcherPtr->drinkPotion();

	witcherPtr = &signWitcher;
	witcherPtr->drinkPotion();

	witcherPtr = &swordWitcher;
	swordWitcher.drinkPotion(false);
}