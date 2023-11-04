#include "ActionCard.hpp"
#include <string>
#include <ctype.h>

using std::cout;
using std::endl;

bool check_positive(const std::string& s) {
	if (int(s.at(5)) > 0) {
		return true;
	}
	else {
		return false;
	}
}

ActionCard::ActionCard() {
	this->setInstruction("");
	this->setType(ACTION_CARD);
}

bool ActionCard::isPlayable() {
	if ((this->getInstruction()).substr(0, 4) == "DRAW" && check_positive(this->getInstruction())) {
		
		return true;
	}
	else if ((this->getInstruction()).substr(0, 4) == "PLAY" && check_positive(this->getInstruction())) {
		
		return true;
	}
	else if ((this->getInstruction()).substr(0, 7) == "REVERSE") {
		
		return true;
	}
	else if ((this->getInstruction()).substr(0, 4) == "SWAP") {
		
		return true;
	}
	else {
		return false;
	}
}

void ActionCard::Print() const {
	cout << "Type: " << this->getType()  << endl;
	cout << "Instruction: " << this->getInstruction() << endl;
	const int* p = this->getImageData();
	if(!this->getImageData()) {
		cout << "Card: " << endl;
		cout << "No image data" << endl;
	}
	else {
		cout << "Card: " << endl;
		for (int i = 0; i < 3; i++) {
			cout << p[i] << " ";
		}
		cout << endl;
	}
}