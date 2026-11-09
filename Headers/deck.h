#pragma once
#include <iostream>
#include "card.h"
using namespace std;

struct Node {
	card Card;
	Node* next;
};

class deck{
public:
	deck();
	//default constructor, initialize a full deck
	deck(const deck& copier);
	//copy constructor
	~deck();
	//destructor
	void shuffle();
	//shuffles deck
	deck& operator =(const deck& copier);
	//assignment operator
	Node* getCards() const;
	//returns pointer to head of card list array
	int getNumCards() const;
	//returns number of cards in array
	card drawCard(int num);
	//returns card in num position in array and then erases it
	card drawTopCard();
	//uses drawCard for the last card in the array
	bool addCard(card c);
	//returns true if card is successfully added to deck
	void printDeck(ostream& outs = cout) const;
	//prints the whole deck using card::output()
	bool isEmpty() const; 
	//returns true if deck is empty
private:
	int numCards;
	Node* head;
};