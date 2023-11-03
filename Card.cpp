#include "Card.hpp"

Card::Card(const Card& rhs) {
	this->instruction_ = rhs.instruction_;
	this->cardType_ = rhs.cardType_;
}

Card::Card() {
	this->instruction_ = "";
	this->cardType_ = POINT_CARD;
}

Card::~Card() {
	std::cout << "Destructor Executed" << std::endl;
	delete this->getImageData();
	
}

Card& Card::operator=(const Card& rhs) {
	if (this != &rhs) {
		this->instruction_ = rhs.instruction_;
		this->cardType_ = rhs.cardType_;
	}
	return *this;
}

Card::Card(Card&& rhs) {
	this->cardType_ = rhs.cardType_;
	this->instruction_ = rhs.instruction_;
}

Card& Card::operator=(Card&& rhs) {
	std::swap(instruction_, rhs.instruction_);
	std::swap(cardType_, rhs.cardType_);
	return *this;
}

std::string Card::getType() const {
	if (this->cardType_ == POINT_CARD) {
		return "Point Card";
	}
	else if (this->cardType_ == ACTION_CARD) {
		return "Action Card";
	}
	else {
		return "No Type";
	}
}

const std::string& Card::getInstruction() const {
	return this->instruction_;
}

void Card::setType(const CardType& type) {
	this->cardType_ = type;
}

void Card::setInstruction(const std::string& instruction) {
	this->instruction_ = instruction;
}

void Card::setDrawn(const bool& drawn) {
	this->drawn_ = drawn;
}

bool Card::getDrawn() const {
	return this->drawn_;
}

void Card::setImageData(int *data) {
	
}

const int* Card::getImageData() const {
	return this->bitmap_;
}