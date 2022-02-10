#include "Player.h"


//player functions

void Player::takeCard(PlayingCard *card)
{
    hand->addCard(card);
    return;
}

std::string Player::showHand()
{
    std::string s;
    s = hand->getAllCardCodes();

    return s;
}

bool Player::startPot(double bet)
{
    bool b = false;
    if (bet >= LOW_START && bet <= HIGH_START)      //is bet within acceptable limits?
    {
        pot = bet;
        b = true;
    }
    return b;
}

bool Player::validBet(double bet)
{
    bool b = false;
    if (bet <= pot && bet >= 0)            //can't bet negative money
        b = true;
    return b;
}

void Player::setBet(double bet)
{
    if (validBet(bet))
        currBet = bet;
    return;
}

int Player::score()
{
    if (hand->getHighScore() <= 21)
        return hand->getHighScore();
    else
        return hand->getLowScore();

}

//Dealer function definitions

PlayingCard* Dealer::dealCard()
{
    PlayingCard *p1;
    p1 = new PlayingCard;
    p1 = deck->dealCard();
    return p1;
}

std::string Dealer::showUpCards()
{
    std::string s1;
    s1 = hand->getAllCardCodes();
    s1[0] = '*';
    s1[1] = '*';
    return s1;
}

bool Dealer::mustStay()
{
    bool b = false;
    int low = hand->getLowScore();
    int high = hand->getHighScore();
    if (high > HIT_LIMIT && high <= BLACKJACK)
        b = true;
    else if (low > HIT_LIMIT)
        b = true;

    return b;
}

void Dealer::takeCard(PlayingCard *card)
{
    if (!mustStay())
        hand->addCard(card);
    return;
}
