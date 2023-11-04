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
	const std::string deez = this->getInstruction();
	cout << "Type: " << this->getType()  << endl;
	cout << "Points: " << this->getInstruction() << endl;
	const int* p = this->getImageData();
	if (!this->getImageData()) {
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

bool PointCard::isPlayable() {
	if (this->getDrawn() == true && isdigit((this->getInstruction()).at(0))) {
		
		return true;
	}
	else {
		
		return false;
	}
}