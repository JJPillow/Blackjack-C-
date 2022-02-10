//#include <iostream>
#include <string>
#include "BlackJackHand.h"
#include "PlayingCard.h"

//default constructor sets all pointers to NULL
BlackJackHand::BlackJackHand()
{
    for(int i = 0;i < HAND_SIZE; i++)
    {
        pcard[i] = NULL;
    }
}

//overloaded constructor
BlackJackHand::BlackJackHand(PlayingCard *c1, PlayingCard *c2)
{
    //set all pointers to null
    for(int i = 0;i < HAND_SIZE; i++)
    {
        pcard[i] = NULL;
    }
    //put playing card c1 in hand
    pcard[0] = new PlayingCard;
    pcard[0] = c1;
    //put playing card c2 in hand
    pcard[1] = new PlayingCard;
    pcard[1] = c2;
}

//checks if possible to add card to hand
bool BlackJackHand::addCard(PlayingCard *card)
{
    int i = 0;
    error = "";
    if (getLowScore() == BLACKJACK)
    {
        error = "Low score is 21!";
        return false;
    }
    else if (isBust())      //check if score of hand < 21
    {
        error = "Hand is bust!";
        return false;
    }
    else if (isFull())      //check if hand has less than 5 cards
    {
        error = "Hand is full!";
        return false;
    }
    else
    {
        while (pcard[i] != NULL)
        {
            i++;
        }
        pcard[i] = card;        //adds card to hand
        return true;
    }
}

int BlackJackHand::getCardCount()
{
    int cardCount = 0;
    for (int i = 0; i < HAND_SIZE; i++)
    {
        if (pcard[i] != NULL)   //if there's an address stored then add to card count
        {
            cardCount++;
        }
    }
    return cardCount;
}

int BlackJackHand::getHighScore()
{
    int hs = getLowScore();
    int aceCount = 0;
    for (int i = 0; i < getCardCount(); i++)
    {
        if (pcard[i]->getValue() == 'A')
            aceCount++;
    }
    if (aceCount > 0)
        hs += 10;           //first ace counts as 11
    return hs;
}

int BlackJackHand::getLowScore()
{
    int ls = 0;
    char val;
    for (int i = 0; i < getCardCount(); i++)
        {
            val = pcard[i]->getValue();
            switch (val)
            {
          //assign values to cards
                case 'A': ls += 1;
                        break;
                case '2': ls += 2;
                        break;
                case '3': ls += 3;
                        break;
                case '4': ls += 4;
                        break;
                case '5': ls += 5;
                        break;
                case '6': ls += 6;
                        break;
                case '7': ls += 7;
                        break;
                case '8': ls += 8;
                        break;
                case '9': ls += 9;
                        break;
                case 'T': ls += 10;
                        break;
                case 'J': ls += 10;
                        break;
                case 'Q': ls += 10;
                        break;
                case 'K': ls += 10;
                        break;
                default: ls += 0;
            }
        }
    return ls;
}

void BlackJackHand::clearHand()
{
    for (int i = 0; i < HAND_SIZE; i++)
    {
      if (pcard[i] != NULL)
      {
         delete pcard[i];
         pcard[i] = NULL;
      }
    }
    return;
}

bool BlackJackHand::isBust()
{
    bool b = false;
    if (getLowScore() > BLACKJACK)  //check if score > 21
            b = true;
    return b;
}

bool BlackJackHand::isFull()
{
    bool b = false;
    if (getCardCount() == HAND_SIZE)    //check if hand has 5 cards
        b = true;
    return b;
}

bool BlackJackHand::canTakeCard()
{
    bool b = false;
    if (getLowScore() != 21 && !isBust() && !isFull())
        b = true;
    return b;
}

std::string BlackJackHand::getAllCardCodes()
{
    std::string cards;
    int i = 0;
    std::string space = " ";
    while (pcard[i] != NULL && i < HAND_SIZE)
            {
                cards += pcard[i]->getCardCode();
                cards += space;
                i++;
            }
    return cards;
}
