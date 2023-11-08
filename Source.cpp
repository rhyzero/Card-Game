#include <iostream>
#include <string>
#include "Card.hpp"
#include "PointCard.hpp"
#include <typeinfo>
#include "ActionCard.hpp"
#include "Deck.hpp"
#include <deque>
#include "Hand.hpp"
#include <algorithm>
#include "Player.hpp"


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

int returnX(vector<int> x) {
	auto temp = x.back();
	x.pop_back();
	return move(temp);
}

int main() {
	string action = "DRAW 2 CARDS";
	string actionx = "PLAY 2 CARDS";
	string actionz = "REVERSE YOUR HAND";
	string actiony = "SWAP";
	string point = "91";
	string pointx = "27";
	string pointa = "14";
	string pointb = "33";
	vector<int> x = { 1, 2, 3 };
	int a = returnX(x);

	int x1 = 20;

	ActionCard action1;
	action1.setInstruction(action);
	ActionCard action2(action1);
	action2.setInstruction(actionx);
	ActionCard action3;
	action3.setInstruction(actionz);
	ActionCard action4;
	action4.setInstruction(actiony);
	PointCard point1;
	point1.setInstruction(point);
	PointCard point2;
	point2.setInstruction(pointx);
	PointCard point3(point1);
	PointCard point4(point1);
	PointCard p2Point1;
	PointCard p2Point2;
	p2Point1.setInstruction(pointa);
	p2Point2.setInstruction(pointb);
	p2Point1.setDrawn(true);
	p2Point2.setDrawn(true);

	Deck<ActionCard> actionDeck;
	Deck<PointCard> pointDeck;

	Hand hand1;
	Hand p2Hand;
	p2Hand.addCard(move(p2Point1));
	p2Hand.addCard(move(p2Point2));

	action1.Print();
	action2.Print();
	point1.Print();

	actionDeck.AddCard(action1);
	actionDeck.AddCard(action2);
	actionDeck.AddCard(action3);
	actionDeck.AddCard(action4);
	pointDeck.AddCard(point3);
	pointDeck.AddCard(point4);
	pointDeck.AddCard(point2);
	pointDeck.AddCard(point1);
	

	cout << "----------------------------" << endl;

	Player p1;
	Player p2;
	p2.setHand(p2Hand);
	p1.setHand(p2.getHand());
	p1.getActionDeck();
	p1.setOpponent(&p2);
	p2.setOpponent(&p1);
	cout << "----------------------------" << endl;
	

	p1.play(actionDeck.Draw());
	p1.play(actionDeck.Draw());
	p1.play(actionDeck.Draw());

	cout << p1.getScore() << endl;
	

	return 0;
}