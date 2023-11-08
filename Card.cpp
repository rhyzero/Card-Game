/*
CSCI335 Fall 2023
Assignment 1 - Card Game
Name Jacky Chen
Date November 02, 2023
Card.cpp implements the Card class and its member functions.
*/

#include "Card.hpp"
#include <array>

//Copy Constructor
Card::Card(const Card& rhs) {
	instruction_ = rhs.instruction_;
	cardType_ = rhs.cardType_;
	bitmap_ = rhs.bitmap_;
	drawn_ = rhs.drawn_;
}

//Default Constructor
Card::Card() {
	instruction_ = "";
	drawn_ = false;
	bitmap_ = nullptr;
}

//Delete bitmap_ pointer
Card::~Card() {
	delete[] bitmap_;
}

//Copy Assignment Operator
Card& Card::operator=(const Card& rhs) {
	if (this != &rhs) {
		instruction_ = rhs.instruction_;
		cardType_ = rhs.cardType_;
		bitmap_ = rhs.bitmap_;
		drawn_ = rhs.drawn_;
	}
	return *this;
}

//Move Constructor
Card::Card(Card&& rhs) {
	cardType_ = std::move(rhs.cardType_);
	instruction_ = std::move(rhs.instruction_);
	drawn_ = std::move(rhs.drawn_);
	bitmap_ = rhs.bitmap_;
	rhs.bitmap_ = nullptr;
}

//Move Assignment Operator
Card& Card::operator=(Card&& rhs) {
	if (this != &rhs) {
		std::swap(cardType_, rhs.cardType_);
		std::swap(drawn_, rhs.drawn_);
		std::swap(instruction_, rhs.instruction_);
		std::swap(bitmap_, rhs.bitmap_);
		delete[] rhs.bitmap_;
		rhs.bitmap_ = nullptr;
	}
	return *this;
}

//Returns the cardType as a string
std::string Card::getType() const {
	if (cardType_ == POINT_CARD) {
		return "POINT_CARD";
	}
	else if (cardType_ == ACTION_CARD) {
		return "ACTION_CARD";
	}
	else {
		return "No Type";
	}
}

//Returns the card's instructions as a string
const std::string& Card::getInstruction() const {
	return instruction_;
}

//Sets the cardType
void Card::setType(const CardType& type) {
	cardType_ = type;
}

//Sets the card's instructions from a string
void Card::setInstruction(const std::string& instruction) {
	instruction_ = instruction;
}

//Sets the card's drawn status
void Card::setDrawn(const bool& drawn) {
	drawn_ = drawn;
}

//Return the card's drawn status
bool Card::getDrawn() const {
	return drawn_;
}

//Set the card's image data 
void Card::setImageData(int *data) {
	bitmap_ = data;
}

//Return the card's image data
const int* Card::getImageData() const {
	return bitmap_;
}