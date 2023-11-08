/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Jacky Chen
Date November 02, 2023
PointCard.cpp implements the PointCard class.
*/
#include "PointCard.hpp"
#include <string>
#include <regex>

using std::cout;
using std::endl;

//Default PointCard constructor
//Sets the cardType to POINT_CARD
PointCard::PointCard() {
	this->setType(POINT_CARD);
}

//Prints out the Card Information
//Type, Instruction / Points, and the Image Data
void PointCard::Print() const {
	cout << "Type: " << this->getType()  << endl;
	cout << "Points: " << this->getInstruction() << endl;
	if (this->getImageData() == 0) {
		cout << "Card: " << endl;
		cout << "No image data" << endl;
	}
	else {
		cout << "Card: " << endl;
		cout << this->getImageData() << endl;
	}
}

//Checks if the card is drawn and the instruction is a number 
bool PointCard::isPlayable() {
	std::regex e("^-?\\d+");
	if (this->getDrawn() == true && std::regex_match(this->getInstruction(), e)) {
		return true;
	}
	else {
		return false; 
	}
}

