/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Jacky Chen
Date November 02, 2023
ActionCard.cpp implements the ActionCard class.
*/

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

//Default ActionCard Constructor
//Sets the cardType to ACTION_CARD
ActionCard::ActionCard() {
	setType(ACTION_CARD);
}

//Returns whether the card instruction is valid or not
bool ActionCard::isPlayable() {
	if ((getInstruction()).substr(0, 4) == "DRAW" && check_positive(getInstruction())) {

		return true;
	}
	else if ((getInstruction()).substr(0, 4) == "PLAY" && check_positive(getInstruction())) {

		return true;
	}
	else if ((getInstruction()).substr(0, 7) == "REVERSE") {

		return true;
	}
	else if ((getInstruction()).substr(0, 4) == "SWAP") {

		return true;
	}
	else {
		return false;
	}
}

//Prints out the Card Information
//Type, Instruction / Points, and the Image Data
void ActionCard::Print() const {
	cout << "Type: " << getType()  << endl;
	cout << "Instruction: " << getInstruction() << endl;
	if(getImageData() == 0) {
		cout << "Card: " << endl;
		cout << "No image data" << endl;
	}
	else {
		cout << "Card: " << endl;
		cout << getImageData() << endl;
	}
}