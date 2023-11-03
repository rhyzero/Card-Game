#include "PointCard.hpp"
#include <string>
#include <ctype.h>

using std::cout;
using std::endl;

bool num_check(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

PointCard::PointCard() {
	this->setInstruction("");
	this->setType(POINT_CARD);
}

void PointCard::Print() const {
	cout << "Type: [" << this->getType() << "]" << endl;
	cout << "Points: [" << this->getInstruction() << "]" << endl;
	cout << "Card: " << "\n" << "[ImageData]" << endl;
}

bool PointCard::isPlayable() {
	if (this->getDrawn() == true && isdigit((this->getInstruction()).at(0))) {
		cout << "This card is playable" << endl;
		return true;
	}
	else {
		cout << "This card is NOT playable" << endl;
		return false;
	}
}