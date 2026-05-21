#include <iostream>
#include <string>
using namespace std;

class ToxicityException {
private:
	string message;

public:
	ToxicityException(string msg) : message(msg) {}

	string getMessage() const { return message; }
};

int main() {
	try {
		int toxicityLevel = 130;
		if (toxicityLevel > 100) {
			throw ToxicityException("Toxicity level is too high!");
		}

		cout << "Toxicity level is acceptable." << endl;
	}
	catch (const ToxicityException& e) {
		cout << "Exception caught: " << e.getMessage() << endl;
	}
}