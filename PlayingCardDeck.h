#ifndef PLAYINGCARDDECK_H_INCLUDED
#define PLAYINGCARDDECK_H_INCLUDED

#include <string>
#include "PlayingCard.h"

class PlayingCardDeck
{
    private:
    static const int NUM_SUITS = 4;     // 4 suits
    static const int NUM_VALUES = 13;   // 13 card values: A, 2-9, T, J, Q, K
    static const int DECK_SIZE = 52;    //standard 52 card deck-no jokers
    PlayingCard *pdeck[DECK_SIZE];      // array of pointers to class objects
    void initializeDeck();              //creates a standard deck

    public:
    //constructors
    PlayingCardDeck();                  //default-creates 52 card deck order:(aces-king, DCHS)
    PlayingCardDeck(int numShuffles);   //creates 52 card deck shuffled numShuffles times
    ~PlayingCardDeck();                 //destructor removes remaining cards and deletes deck

    //member functions
    PlayingCard* dealCard();            //returns pointer to card on top of deck, returns null if no more cards
    bool shuffle(int numShuffles);      //shuffles cards if no cards have been dealt
    void reset();                       //resets to deck of 52 unshuffled cards
    std::string getAllCardCodes();      //returns string of value and suit for cards remaining in the deck
    int getCountUsed();                 //returns number of cards dealt from deck
    int getCountRemain();               //returns number of cards left in deck

};


#endif // PLAYINGCARDDECK_H_INCLUDED
