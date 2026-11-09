#pragma once
#include "deck.h"
using namespace std;

class player {
public:
    player(int pid);
    //constructor, assign pid to player's id
    //all other fields initialized to nullptr or 0
    player();
    //default constructor, assigns id from 1 - 8 sequentially
    ~player(); //destructor

    deck* getHand() const;
    //returns player's hand
    deck* getArmy() const;
    //returns player's army
    deck* setHand(deck* toSet);
    //sets player's hand
    deck* setArmy(deck* toSet);
    //sets player's army

    friend bool swapHands(player& swap1, player& swap2);
    //swaps players' hands
    //returns true if successful, false if not
    friend bool swapArmies(player& swap1, player& swap2);
    //swaps players' armies
    //returns true if successful, false if not

    int getTurnOrder() const;
    //return turn order number
    void setTurnOrder(int num);
    //set turn order number
    int getVictory() const;
    //return number of cards in victory pile
    int winCards(int won);
    //add won number of cards to player's victory pile

    bool build(int sector, card* toPlay);
    //build all cards in toPlay onto square sector
    //sector should be index 0 - 8
    //return true if successful, false if not
    bool battle(int sector, card toDeclare);
    //declare a card onto sector, call square battle function
    //sector should be index 0 - 8
    //return true if successful, false if not
    bool pass();
    //calls passTurn(); from dealer early
private:
    int id;
    deck* army;
    deck* hand;
    int turnOrder;
    int victoryPile;
};