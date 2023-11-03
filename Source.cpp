#include <iostream>
#include <string>
#include "Card.hpp"
#include "PointCard.hpp"
#include <typeinfo>

using namespace std;

enum Seasons {
	SPRING,
	SUMMER,
};

void zxzxz() {
	Seasons thisSeason = SUMMER;
	int type = static_cast<int>(thisSeason);
	cout << type << endl;
	if (type == 0) {
		cout << "The season is Spring" << endl;
	}
	else if (type == 1) {
		cout << "The season is Summer" << endl;
	}

}

int main() {
	
	string testInstructions = "5";
	PointCard card1;
	card1.setInstruction(testInstructions);
	cout << card1.getInstruction() << endl;
	
	PointCard card2;
	card1.Print();
	
	return 0;
}