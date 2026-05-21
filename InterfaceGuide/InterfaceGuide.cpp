#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class IWitcher {
public:
	virtual void castSign() = 0;
	virtual ~IWitcher() {}
};

class Geralt : public IWitcher {
private:
	string Aard;
	int damage;
public:
	Geralt(string Aard, int dmg) : Aard(Aard), damage(dmg) {}

	void castSign() override {
		cout << "Геральт кастує знак: " << Aard << " з шкодою: " << damage << endl;
	}
};

class Vesemir : public IWitcher {
private:
	string Quen;
	int shieldStrength;

public:
	Vesemir(string Quen, int ST) : Quen(Quen), shieldStrength(ST) {}

	void castSign() override {
		cout << "Весемір кастує знак: " << Quen << " з силою щита: " << shieldStrength << endl;
	}
};

int main() {
	SetConsoleOutputCP(1251);

	Geralt geralt("Aard", 50);
	Vesemir vesemir("Quen", 60);

	IWitcher* witcherPtr;

	witcherPtr = &geralt;
	witcherPtr->castSign();

	witcherPtr = &vesemir;
	witcherPtr->castSign();
}