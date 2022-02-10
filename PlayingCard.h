#ifndef PLAYINGCARD_H_INCLUDED
#define PLAYINGCARD_H_INCLUDED

#include <string>


class PlayingCard
{
    private:
    //member variables
    char value;
    char suit;

    public:
    //constuctors
    PlayingCard();
    PlayingCard(char myValue, char mySuit);

    //member functions
    bool setCard(char myValue, char mySuit);
    char getValue() { return value; }
    char getSuit() { return suit; }
    std::string getCardCode();
    bool isValid();
};


#endif // PLAYINGCARD_H_INCLUDED
