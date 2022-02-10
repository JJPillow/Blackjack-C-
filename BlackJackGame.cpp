#include <iostream>
#include <string>
#include "Player.h"
#include <iomanip>
#include "BlackJack.h"
#include "BlackJackHand.h"
#include "PlayingCardDeck.h"
#include "PlayingCard.h"

using namespace std;

bool askQ(string q);

int main()
{
    double startMoney = 0;
    double bet = -1;
    int winner;

    string qBlack = "Do you want to play blackjack(y/n)? ";
    string qPot = "How much money would you like to start with (1.00-500.00)? ";
    string qWager = "How much would you like to wager (.01-";
    string qHit = "\nWould you like to hit (y/n)? ";
    string qCont = "\nWould you like to keep playing(y/n)";

    cout << fixed << setprecision(2);

    //does player want to play?
    bool play = askQ(qBlack);
    BlackJack game = BlackJack(startMoney);

    //if yes, start game
    if (play)
    {

        while (!game.getMoney(startMoney))    //make sure starting pot is within limits
        {
            cout << qPot;
            cin >> startMoney;
        }

    }
    game = BlackJack(startMoney);    //set starting pot value

    while (play)
    {
        //get wager from player
        while (!game.player.validBet(bet))
        {
            cout << qWager << game.player.showPot() << ")? " << endl;
            cin >> bet;
            game.player.setBet(bet);
        }

        //deal starting hand
        cout << "\nnow";
        cout << endl << game.dealer.showTotalBet();
        cout << endl << game.dealer.dealCard();
        game.startGame();
        cout << "\later";
        cout << game.getCards();
        cout << "\nPlayer's bet is :$" << game.player.showBet() << endl;

        //does player want more cards
        bool hit = true;
        hit = askQ(qHit);
        while(hit && game.player.hand->getLowScore() < 21)
        {
            game.hit();
            cout << game.getCards();
            if (game.player.hand->getLowScore() > 21)
                cout << "\nPlayer is bust!";
            else if (game.player.hand->getLowScore() == 21)
                cout << "\nPlayer has blackjack";
            else
                hit = askQ(qHit);
        }

        //dealer hits or stays
        game.dealerHit();
        cout << game.getAllCards();


        //determine winner
        winner = game.win();
        if (winner == 1)
        {
            cout << "\nPlayer wins!";
        }
        else if (winner == 2)
        {
            cout << "\nComputer wins!";
        }
        else
        {
            cout << "\nIt's a push: computer and player tie!";
        }
        cout <<"\nPlayer's pot is :$" << game.player.showPot() << endl;
        bet = -1;
        cout << game.deckReset();

        //continue playing
        if (game.player.showPot() > 0)
            play = askQ(qCont);
        else
        {
            cout << "\nYour money is all gone! \nThanks for playing.";
            break;
        }
        game.endGame();
    }
    if (game.player.showPot() > 0)
    {
        cout << "\nYou started with: $" << startMoney << ".";
        if (game.player.showPot() >= startMoney)
            cout << "\nYour winnings are: $" << game.player.showPot() - startMoney;
        else
            cout << "\nYou've lost: $" << startMoney - game.player.showPot();
        cout << " and you leave with $" << game.player.showPot() << " in your pocket." << endl;
        cout << "Thanks for playing." << endl;
    }

    return 0;
}



bool askQ(string q)
{
    char ans = 'b';
    bool b = false;
    while (ans != 'Y' && ans != 'N' && ans != 'y' && ans != 'n')
    {
        cout << q << endl;
        cin >> ans;
    }
    if (ans == 'Y' || ans == 'y')
        b = true;
    return b;
};

