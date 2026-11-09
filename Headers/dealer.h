#pragma once
#include <iostream>
#include "map.h"
#include "player.h"
using namespace std;

class dealer {
public:
    dealer();
    //default constructor, initialize currentTurn to -1
    ~dealer();
    //destructor
    void startGame();
    //starts the game, output intro & title
    //ask for input to start, then input # of players
    //create array containing the players and point to it
    //call dealCards(); and initialBuilding();
    //then go to first player's turn
    void endGame();
    //tally up each players' victory piles
    //declare winner
    //ask for another game or to abort program

    void passTurn();
    //increment currentTurn
    //then call turn(); for the new player

    //give information to the player on their turn
    void showMap() const; 
    //show 3x3 grid map with number of cards built on each
    //each square should have 2 numbers
    //one for cards built and one for sectorID
    void showHand() const;
    //show hand; should clearly show cards' ranks, suits, and in order
private:
    int currentTurn;
    player* players;
    map field;
    void dealCards();
    //initialize the correct number of cards for the number of players
    //split evenly to each player, set leftover cards to random squares
    //then call initialBuilding();
    void initialBuilding();
    //ask each player to input sector IDs in a comma-separated list
    //then ask for comma-separated list of number of cards to place
    //should build exactly 10 cards for each player
    //alternatively, player can choose to randomize the initial building
    void turn();
    //calls endGame(); if checkEndCondition() == true;
    //else, calls draw(); then askAction(); for the player of currentTurn
    void draw();
    //add card from player's army to their hand
    void askAction();
    //showMap(); and showHand();
    //give list of possible actions then ask for action input
    //ask for action, sector to act in, card(s) to play
    //and call specified action function for the current player
    //if invalid action, ask for re-input
    bool checkEndCondition();
    //returns true if any player has no cards in both
    //their hand and their army
};