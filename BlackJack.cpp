#include "BlackJack.h"

bool BlackJack::getMoney(double money)
{
    if (player.startPot(money))
    {
        player.startPot(money);
        return true;
    }
    else
        return false;
}

void BlackJack::hit()
{
    if (player.hand->canTakeCard())
    {
        player.takeCard(dealer.dealCard());
    }
    return;
}

void BlackJack::dealerHit()
{
    if (player.hand->getLowScore()< BJACK && player.hand->getCardCount() < MAX_HAND)      //dealer doesn't take cards if player already wins or busts
    {
        while (!dealer.mustStay())
        dealer.takeCard(dealer.dealCard());
    }

    return;
}

int BlackJack::win()
{
    int winner = 0;         //0 if push, 1 if player wins, 2 if computer wins
    //player automatically wins
    if (player.hand->getHighScore() == BJACK)
        winner = 1;
    else if (player.hand->getHighScore() > BJACK)
    {
        if (player.hand->getLowScore() == BJACK)
            winner = 1;
        else if (player.hand->getLowScore() > BJACK)
            winner = 2;
        else
        {
            if (dealer.hand->getHighScore() == BJACK)
                winner = 2;
            else if (dealer.hand->getHighScore() > BJACK)
            {
                if (dealer.hand->getLowScore() == BJACK)
                    winner = 2;
                else if (dealer.hand->getLowScore() > BJACK)
                    winner = 1;
                else
                {
                    if (player.hand->getLowScore() > dealer.hand->getLowScore())
                        winner = 1;
                    else if (player.hand->getLowScore() > dealer.hand->getLowScore())
                        winner = 2;
                }
            }
            else
            {
                if (player.hand->getLowScore() > dealer.hand->getHighScore())
                    winner = 1;
                else if (player.hand->getLowScore() < dealer.hand->getHighScore())
                    winner = 2;
            }
        }
    }
    else
    {
        if (dealer.hand->getHighScore() == BJACK)
            winner = 2;
        else if (dealer.hand->getHighScore() > BJACK)
        {
            if (dealer.hand->getLowScore() > BJACK)
                winner = 1;
            else if (dealer.hand->getLowScore() == BJACK)
                winner = 2;
            else
            {
                if (player.hand->getHighScore() > dealer.hand->getLowScore())
                    winner = 1;
                else if (player.hand->getHighScore() < dealer.hand->getLowScore())
                    winner = 2;
            }
        }
        else
        {
            if (player.hand->getHighScore() > dealer.hand->getHighScore())
                winner = 1;
            else if (player.hand->getHighScore() < dealer.hand->getHighScore())
                winner = 2;
        }
    }
    if (winner == 1)
        player.addBet(player.showBet());
    else if (winner == 2)
        player.addBet(-player.showBet());
    return winner;
}

std::string BlackJack::deckReset()
{
    std::string s = "\n";
    if (dealer.deck->getCountRemain() <= LOW_DECK)
        {
            dealer.deck->reset();
            s = "\nReshuffling deck";
            dealer.deck->shuffle(6);
        }
    return s;
}

void BlackJack::startGame()
{
    player.takeCard(dealer.dealCard());
    dealer.takeCard(dealer.dealCard());
    player.takeCard(dealer.dealCard());
    dealer.takeCard(dealer.dealCard());
    return;
}

std::string BlackJack::getCards()
{
    std::string s = "\nThe table now shows: ";
    s += "\nDealer has: ";
    s += dealer.showUpCards();
    s += "\nPlayer has: ";
    s += player.showHand();

    return s;
}

std::string BlackJack::getAllCards()
{
    std::string s = "\n\nShowing the dealer's cards: ";
    s += "\nDealer has: ";
    s += dealer.showHand();
    s += "\nPlayer has: ";
    s += player.showHand();

    return s;
}

void BlackJack::endGame()
{
    player.clearHand();
    dealer.clearHand();
    return;
}
