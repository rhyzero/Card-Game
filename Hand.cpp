/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Jacky Chen
Date November 02, 2023
Hand.cpp implements the Hand class.
*/

#include "Hand.hpp"
#include <algorithm>
#include <string>

//Default Hand constructor
Hand::Hand() {
}

//Hand destructor 
//Clears out the card vector 
Hand::~Hand() {
	cards_.clear();
}

//Copy Constructor 
Hand::Hand(const Hand& other) {
	cards_ = other.cards_;
}

//Copy Assignment Operator
Hand& Hand::operator=(const Hand& other) {
	if (this != &other) {
		cards_ = other.cards_;
	}
	return *this;
}

//Move Constructor
Hand::Hand(Hand&& other) {
	cards_ = std::move(other.cards_);
}

//Move Assignement Operator
Hand& Hand::operator=(Hand&& other) {
	if (this != &other) {
		std::swap(cards_, other.cards_);
	}
	return *this;
}

//Returns a const ref to the deque of cards
const std::deque<PointCard>& Hand::getCards() const {
	return cards_;
}

//Add a point card to the hand 
//Set the drawn status to true
void Hand::addCard(PointCard&& card) {
	cards_.push_back(card);
	cards_.back().setDrawn(true);
}

//Returns if the deque is empty
bool Hand::isEmpty() const {
	return cards_.empty();
}

//Reverses the deque
void Hand::Reverse() {
	std::reverse(cards_.begin(), cards_.end());
}

//Returns the amount of points from the point card 
int Hand::PlayCard() {
	if (isEmpty()) {
		throw ("Hand is empty");
	}
	else {
		auto temp = cards_.front();
		cards_.pop_front();
		return stoi(temp.getInstruction());
	}
}