#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"
#include <string>

using namespace std;

class Deck {
public:

    // implements the “big three”: copy constructor, copy assignment operator, and destructor,
    // default constructor
    Deck();

     // copy constructor
    Deck (const Deck& rhs);

    // copy assignment operator
    Deck& operator = (const Deck& rhs);

    // destructor
    ~ Deck();

    // populates the deck with 52 cards
    void populate();

    // shuffles the cards in the deck by performing cardsLeft^2 swaps of two randomly chosen cards in the deck
    void shuffle();

    //includes a member function that removes a card from the deck and returns its value,
    Card removeCard();

    // add a card to the deck (or returns false if there is no physical space in the deck.
    bool addCard(Card v);



private:

    //●	have these 3 private members:
    //○	Card* cards (pointer to array of cards)
    //○	int arraySize (physical size of array)
    //○	int cardsLeft (logical size of array)
    Card* cards;
    int arraySize;
    int cardsLeft;

    // initialize a variable for the card we get
    int thiscard;
};



#endif //BLINDMANSBLUFF_DECK_H