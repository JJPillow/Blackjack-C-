#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "BlackJackHand.h"
#include "PlayingCardDeck.h"
#include "PlayingCard.h"
#include <string>

class Player
{
    private:
    double pot;                            //variable to hold player's money
    static const double HIGH_START = 500.00;    //upper limit for player's starting money
    static const double LOW_START = 1.00;       //lower limit for player's starting money
    double currBet;                             //variable to hold current bet;

    public:
    BlackJackHand *hand;                        //hand has to be public for use by dealer

    //constructor
    Player()  {   hand = new BlackJackHand;}       //allocates memory for a hand object for the player
    ~Player() {   delete hand;}                    //deletes the allocated memory for the hand object

    //member functions
    void takeCard(PlayingCard *);           //takes a card and adds it to hand
    std::string showHand();                 //shows all cards in hand
    bool startPot(double bet);              //player's starting money
    bool validBet(double bet);              //checks if bet is valid
    void setBet(double bet);                //sets current bet
    void addBet(double bet){ pot += bet; return;}     //adds or subtracts bet amount if won or lost
    double showPot() {return pot;}       //shows how much money player has
    int score();
    void clearHand()    {hand->clearHand(); return;}
    double showBet()    {return currBet;}
};

class Dealer:public Player
{
    private:

    static const int HIT_LIMIT = 16;        //dealer stands on 16
    static const int BLACKJACK = 21;        //blackjack is a score of 21
    static const int SHUFF = 5;             //shuffle number for deck constructor


    public:

    PlayingCardDeck *deck;                  //deck is public so deck functions can be called (reset, shuffle, etc.)

    //contructor & destructor
    Dealer() {deck = new PlayingCardDeck(SHUFF);}      //in addition to the hand object from player, dealer also has a deck
    ~Dealer() {delete deck;}                            //deletes the deck

    //member functions
    PlayingCard* dealCard();                //takes first card from deck
    std::string showUpCards();              //shows first card in hand as **, shows all other cards in hand
    bool mustStay();                        //dealer stands if (16 < high score <= 21) or (low score >= 16)
    void takeCard(PlayingCard *);           //takes a card and adds it to hand if dealer doesn't have to stay
    void startBet(double bet) { }          //overrides player bet function dealer has no bet
    void addBet(double bet) { }            //overrides player bet function dealer has no bet
    double showTotalBet() {return 0;}      //dealers bet is zero
};

#endif // PLAYER_H_INCLUDED
