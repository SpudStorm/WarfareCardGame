#pragma once
#include <iostream>
using namespace std;

class card {
public:
	card(int rankVal, int suitVal);
	//creates a card object of specified rank and suit
	//does not check for validity
	card();
	//default constructor, generates ace of spades
	~card();
	//destructor
	friend ostream& operator <<(ostream& outs, card insertCard);
	//inserts card into output stream
	friend istream& operator >>(istream& ins, card& added);
	//inserts card into input stream
	friend bool operator <(const card& card1, const card& card2);
	//return true if rank of card1 less than card2
	//false if equal or more than card2
	friend bool operator >(const card& card1, const card& card2);
	//return true if rank of card1 more than card2
	//false if equal or less than card2
	friend bool operator ==(const card& card1, const card& card2);
	//return true if ranks equal, false if not
	card& operator=(const card& copier);
	//assign card value to another card
	void printRankName(ostream& outs) const;
	//prints rank name to output stream for debugging
	void printSuitName(ostream& outs) const;
	//prints suit name to output stream for debugging
private:
	int rank;
	int suit;
	bool isFaceCard() const;
	//returns true if card is a face card i.e. jack, queen, king
	//else print error message and return false
	bool isValid() const; //check rank and suit valid
};