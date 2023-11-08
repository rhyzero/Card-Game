/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name Jacky Chen
Date November 02, 2023
Deck.cpp implements the Deck class.
*/
#pragma once
#include "Deck.hpp"

//Deck constructor
template<typename CardType>
Deck<CardType>::Deck() {
}

template<typename CardType>
Deck<CardType>::~Deck() {
}

template<typename CardType>
void Deck<CardType>::AddCard(const CardType& card) {
	this->cards_.push_back(card);
}

template <typename CardType>
CardType&& Deck<CardType>::Draw() {
	if (!IsEmpty()) {
		drawnCard = std::move(cards_.back());
		cards_.pop_back();
		return std::move(drawnCard);
	}
	throw std::runtime_error("Empty deck");
}


template<typename CardType>
bool Deck<CardType>::IsEmpty() const {
	if (this->cards_.empty()) {
		return true;
	}
	else {
		return false;
	}

}



template<typename CardType>
void Deck<CardType>::Shuffle() {
	std::mt19937 mt;
	mt.seed(2028358904);
	std::shuffle(this->cards_.begin(), this->cards_.end(), mt);
}



template<typename CardType>
int Deck<CardType>::getSize() const {
	return this->cards_.size();
}



template<typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const {
	return cards_;
}
