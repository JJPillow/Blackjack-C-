#include "PlayingCard.h"
#include "PlayingCardDeck.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

    void PlayingCardDeck::initializeDeck()
    {
        // arrays of values and suits for normal cards
        char values[NUM_VALUES] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
        char suits[NUM_SUITS] = {'D','C','H','S'};

        // Initialize a card deck
        for(int i=0;i<NUM_SUITS;i++)
            for(int j=0;j<NUM_VALUES;j++)
                pdeck[i*13 + j] = new PlayingCard(values[j],suits[i]);
        return;
    }

    //constructors
    PlayingCardDeck::PlayingCardDeck()                  //default-creates 52 card deck order:(aces-king, DCHS)
    {
        //create deck
        initializeDeck();
        srand(time(0));
    }

    PlayingCardDeck::PlayingCardDeck(int numShuffles)   //creates 52 card deck shuffled numShuffles times
    {
        //create deck
        initializeDeck();
        srand(time(0));

        //shuffle the deck
        shuffle(numShuffles);

    }

    PlayingCardDeck::~PlayingCardDeck()                 //destructor removes remaining cards and deletes deck
    {
        for (int i = 0; i < DECK_SIZE; i++)
        {
            if (pdeck[i] != NULL)
            {
                delete pdeck[i];
                pdeck[i] = NULL;
            }
        }
        delete [ ] pdeck;
    }

    //member functions
    PlayingCard* PlayingCardDeck::dealCard()            //returns pointer to card on top of deck, returns null if no more cards
    {
        PlayingCard *card;
        card = NULL;
        int i = 0;
        bool b = false;
        while (pdeck[i] == NULL && i < DECK_SIZE)
            i++;
        if (i < DECK_SIZE)
        {
            card = pdeck[i];
            pdeck[i] = NULL;
            b = true;
        }
        if (!b)
            std::cout << "Error: no more cards in deck!" << std::endl;
        return card;
    }

    bool PlayingCardDeck::shuffle(int numShuffles)      //shuffles cards if no cards have been dealt
    {
        bool b = false;
        if (getCountRemain() == DECK_SIZE)
        {
            //shuffle code here
            for (int j = 0; j < numShuffles; j++)
                for (int i = 0; i < DECK_SIZE; i++)
                {
                    int other = rand()%DECK_SIZE;
                    PlayingCard* temp = pdeck[i];
                    pdeck[i] = pdeck[other];
                    pdeck[other] = temp;
                }

            b = true;
        }
        if (!b)
            std::cout << "Error: Deck could not be shuffled!" << std::endl;
        return b;
    }

    void PlayingCardDeck::reset()                       //resets to deck of 52 unshuffled cards
    {
        //remove old deck
        for (int i = 0; i < DECK_SIZE; i++)
        {
            if (pdeck[i] != NULL)
            {
                delete pdeck[i];
                pdeck[i] = NULL;
            }
        }

        //create new deck
        initializeDeck();

        return;
    }

    std::string PlayingCardDeck::getAllCardCodes()     //returns string of value and suit for cards remaining in the deck
    {
        std::string cards = "";
        for (int j = 0; j < NUM_SUITS; j++)
        {
            for (int i = 0; i < NUM_VALUES; i++)
            {
                if (pdeck[j*NUM_VALUES + i] != NULL)
                {
                    cards += pdeck[j*NUM_VALUES + i]->getCardCode();
                    cards += " ";
                }
            }
            cards += "\n";
        }
        return cards;
    }

    int PlayingCardDeck::getCountUsed()                 //returns number of cards dealt from deck
    {
        int used = 0;
        for (int i = 0; i < DECK_SIZE; i++)
        {
            if (pdeck[i] == NULL)
                used ++;
        }
        return used;
    }

    int PlayingCardDeck::getCountRemain()              //returns number of cards left in deck
    {
        int remain = DECK_SIZE - getCountUsed();

        return remain;
    }
