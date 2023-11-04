#include <iostream>
#include <string>
#include "Card.hpp"
#include "PointCard.hpp"
#include <typeinfo>
#include "ActionCard.hpp"
#include "Deck.hpp"

using namespace std;

enum Seasons {
	SPRING,
	SUMMER,
};

void zxzxz() {
	Seasons thisSeason = SUMMER;
	int type = static_cast<int>(thisSeason);
	cout << type << endl;
	if (type == 0) {
		cout << "The season is Spring" << endl;
	}
	else if (type == 1) {
		cout << "The season is Summer" << endl;
	}

}

int main() {

	cout << "ACTION CARD TESTING BELOW" << endl;
	cout << "-------------------------------" << endl;
	
	ActionCard action1;
	ActionCard action2;
	ActionCard action3;
	ActionCard action4;
	string testPoint = "5";
	string testAction = "SWAP HAND WITH OPPONENT";
	string testAction1 = "DRAW 5 CARDS";
	string testAction2 = "PLAY 3 CARDS";

	int arr[] = { 50,40,30 };

	action1.setInstruction(testAction);
	action2.setInstruction(testAction1);
	action3.setInstruction(testAction2);
	
	action1.setImageData(arr);
	action4 = std::move(action1);
	action4.Print();

	cout << "DECK TESTING" << endl;
	cout << "-------------------------------" << endl;
	
	Deck<ActionCard> actionDeck;

	actionDeck.AddCard(action1);
	actionDeck.AddCard(action2);
	actionDeck.AddCard(action3);

	ActionCard card1 = actionDeck.Draw();
	ActionCard card2 = actionDeck.Draw();
	ActionCard card3 = actionDeck.Draw();
	card1.Print();
	card2.Print();
	card3.Print();



	return 0;
}