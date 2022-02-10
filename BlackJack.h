#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED

#include "Player.h"
#include "BlackJackHand.h"
#include "PlayingCard.h"
#include "PlayingCardDeck.h"
#include <string>
#include <iostream>

class BlackJack
{
    private:

    static const int LOW_DECK = 10;     //deck reshuffles when #of cards gets to LOW_DECK
    static const int BJACK = 21;        //BlackJack's magic number is 21
    static const int MAX_HAND = 5;      //Only allowed 5 cards in a hand

    public:
    Player player;                      //adds a player to the game
    Dealer dealer;                      //adds a dealer to the game

    //constructor
    BlackJack(double money) { getMoney(money);  }
    ~BlackJack()  {   }

    //member functions
    bool getMoney(double money);        //sets the starting value of the player's pot
    void hit();                         //adds a card to player's hand if allowed
    void dealerHit();                   //adds cards to dealer hand while allowed
    int win();                          //determines a winner
    std::string deckReset();            //puts all cards back in deck and reshuffles
    void startGame();                   //puts two card in dealer's hand & player's hand
    std::string getCards();             //returns string showing hands with dealer's hole card down
    std::string getAllCards();          //returns string showing all cards in both hands
    void endGame();                     //empties both hands
};

#endif // BLACKJACK_H_INCLUDED
