#ifndef BLACKJACKHAND_H_INCLUDED
#define BLACKJACKHAND_H_INCLUDED

#include <string>
#include "PlayingCard.h"

class BlackJackHand
{
    private:

    //member variables
    static const int HAND_SIZE = 5;        //max cards in hand
    static const int BLACKJACK = 21;       //blackjack score
    PlayingCard *pcard[HAND_SIZE];   //create an array of pointers to playing card objects
    std::string error;

    public:

    //default constructor
    BlackJackHand();
    //overloaded contructor
    BlackJackHand(PlayingCard *c1, PlayingCard *c2);

    //member functions
    bool addCard(PlayingCard *card);    //adds a card to hand
    int getCardCount();                 //returns number of cards in hand
    int getHighScore();                 //returns score for hand (first ace = 11)
    int getLowScore();                  //returns score for hand (ace = 1)
    void clearHand();                   //deletes all cards from hand
    bool isBust();                      //true if low score > 21
    bool isFull();                      //true if hand has 5 cards
    bool canTakeCard();                 //true if hand has less than 5 cards & is not bust
    std::string getAllCardCodes();      //displays cards in hand
    std::string getError() {return error;}
};



#endif // BLACKJACKHAND_H_INCLUDED
