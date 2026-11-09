#pragma once
#include "card.h"
using namespace std;

class square {
public:
    square(); //default constructor
    ~square(); //destructor
    int getCardsBuilt();
    //return number of cards built on square
    int setCardsBuilt(int setter);
    //sets number of cards built on square
    bool build(card* toBuild);
    //build one or more cards onto square
    //WARNING: card values lost in building
    //return true if successful, false if not
    void battle(int declaringPlayer, card declare);
    //declares a battle
    //query opponents to contest the battle
    //if contest, go to fight(); if not, go to victory();
private:
    int built;
    card winningCard;
    //keep track of winning card as a member var
    void fight(const int* ids);
    //set the players if the argument's IDs to fight
    //if cards equal, go to war; else, go to victory();
    void war();
    //initiate war mechanic
    void cardEffect(card winner);
    //does a card effect depending on rank of winner
    //should determine effect via an enum block
    void victory(int winner);
    //give all built cards and used cards to winner's victory pile
};