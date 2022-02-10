#include "PlayingCard.h"


//default constructor
PlayingCard::PlayingCard()
{
    value = '0';
    suit = '0';
}

//overloaded constructor
PlayingCard::PlayingCard(char myValue, char mySuit)
{
    value = '0';
    suit = '0';
    setCard(myValue, mySuit);
}

bool PlayingCard::setCard(char myValue, char mySuit)
{
    if ((myValue == 'A' || myValue == '1' || (myValue >= '2' && myValue <= '9') || myValue == 'T'
         || myValue == 'J' || myValue == 'Q' || myValue == 'K') && (mySuit == 'C' || mySuit == 'D'
            || mySuit == 'S' || mySuit == 'H'))
        {
            value = myValue;
            suit = mySuit;
            return true;
        }

    else if ((myValue == 'Z') && (mySuit == 'B' || mySuit == 'R'))
        {
            value = myValue;
            suit = mySuit;
            return true;
        }
    else
        return false;
}

std::string PlayingCard::getCardCode()
{
    std::string str1, str2, str3;
    str1 = value;
    str2 = suit;
    str3 = str1 + str2;

    return str3;
}

bool PlayingCard::isValid()
{
    if ((value == 'A' || value == '1' || (value >= '2' && value <= '9') || value == 'T'
         || value == 'J' || value == 'Q' || value == 'K') && (suit == 'C' || suit == 'D'
            || suit == 'S' || suit == 'H'))
        return true;
    else if ((value == 'Z') && (suit == 'B' || suit == 'R'))
        return true;
    else
        return false;
}


