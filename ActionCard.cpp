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
		cout << "This card is playable" << endl;
		return true;
	}
	else if ((this->getInstruction()).substr(0, 4) == "PLAY" && check_positive(this->getInstruction())) {
		cout << "This card is playable" << endl;
		return true;
	}
	else if ((this->getInstruction()).substr(0, 7) == "REVERSE") {
		cout << "This card is playable" << endl;
		return true;
	}
	else if ((this->getInstruction()).substr(0, 4) == "SWAP") {
		cout << "This card is playable" << endl;
		return true;
	}
	else {
		return false;
	}
}

void ActionCard::Print() const {
	cout << "Type: [" << this->getType() << "]" << endl;
	cout << "Instruction: [" << this->getInstruction() << "]" << endl;
	cout << "Card: " << "\n" << "[ImageData]" << endl;
}