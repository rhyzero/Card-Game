/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Jacky Chen
Date November 02, 2023
Player.cpp implements the Player class.
*/

#include "Player.hpp"
#include <iostream>

//Default constructor
Player::Player() : score_(0), opponent_(nullptr) {
	actiondeck_ = new Deck<ActionCard>();
	pointdeck_ = new Deck<PointCard>();
}

//Player Destructor
Player::~Player() {
	delete opponent_;
	opponent_ = nullptr;
	delete actiondeck_;
	actiondeck_ = nullptr;
	delete pointdeck_;
	pointdeck_ = nullptr;
}

//Returns const reference to the player's hand
const Hand& Player::getHand() const{
	return hand_;
}

//Sets the player's hand to a const hand reference
void Player::setHand(const Hand& Hand) {
	hand_ = Hand;
}

//Returns the player's score
int Player::getScore() const{
	return score_;
}

//Sets the player's score a const int reference
void Player::setScore(const int& score) {
	score_ = score;
}

//Plays the drawn card from the action deck
//Prints out the current card being played and the card's instructions
//Throws an error if the hand is empty
void Player::play(ActionCard&& card) {
	std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
	int num = 0;
	if (card.getInstruction().substr(0, 4) == "DRAW" && card.isPlayable()) {
		num = std::stoi(card.getInstruction().substr(5, 6));
		for (int i = 0; i < num; i++) {
			drawPointCard();
		}
	}

	else if (card.getInstruction().substr(0, 4) == "PLAY" && card.isPlayable()) {
		num = std::stoi(card.getInstruction().substr(5, 6));
		for (int i = 0; i < num; i++) {
			if (hand_.isEmpty()) {
				throw std::runtime_error("Empty hand");
			}
			else {
				playPointCard();
			}
		}
	}
	else if (card.getInstruction().substr(0, 7) == "REVERSE" && card.isPlayable()) {
		hand_.Reverse();
	}

	else if (card.getInstruction().substr(0, 4) == "SWAP" && card.isPlayable()) {
		std::swap(hand_, opponent_->hand_);
	}
}


//Checks if the pointdeck_ pointer is pointing to a deck then draws a card from the point deck using the draw function 
void Player::drawPointCard() {
	if (pointdeck_ != nullptr) {
		hand_.addCard(std::move(pointdeck_->Draw()));
	}
}

//Checks if the hand is empty then plays a card and adds the points to the player's score
void Player::playPointCard() {
	if (!hand_.isEmpty()) {
		score_ += hand_.PlayCard();
	}
}

//Sets the opponent_ pointer to another player
void Player::setOpponent(Player* opponent) {
	opponent_ = opponent;
}

//Returns the opponent pointer
Player* Player::getOpponent() {
	return opponent_;
}

//Sets the actiondeck_ pointer to an action deck
void Player::setActionDeck(Deck<ActionCard>* actiondeck) {
	actiondeck_ = std::move(actiondeck);
	
}

//Returns the actiondeck_ pointer
Deck<ActionCard>* Player::getActionDeck() {
	return actiondeck_;
}

//Sets the pointdeck_ pointer to a point deck
void Player::setPointDeck(Deck<PointCard>* pointdeck) {
	pointdeck_ = std::move(pointdeck);
	
}

//Returns the pointdeck_ pointer
Deck<PointCard>* Player::getPointDeck() {
	return pointdeck_;
}