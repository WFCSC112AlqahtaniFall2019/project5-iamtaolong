#include "Deck.h"
#include <string>
#include <iostream>

using namespace std;

// default constructor
Deck :: Deck() {

    // initialize all the related variables
    thiscard = 0;
    arraySize = 52;
    cards = new Card[arraySize];
    cardsLeft = 52;
}


// copy constructor
Deck :: Deck (const Deck& rhs ){

    // copy starts from arraySize
    arraySize = rhs.arraySize;
    cards = new Card[arraySize];

    // use for-loop to copy each element
    for (int i = 0; i < arraySize;i ++){
        cards[i] = rhs.cards[i];
    }

    // copy this card to the deck
    thiscard = rhs.thiscard;
    cardsLeft = rhs.cardsLeft;
}


// copy assignment operator in copy and swap idiom
Deck& Deck :: operator = (const Deck& rhs) {

    //initialize a temp
    Deck tmp(rhs);

    // swap
    swap(cards, tmp.cards);
    return *this;
}



// destructor
Deck :: ~ Deck() {

    // delete the cards[]
    delete [] cards;
}


// populates the deck with 52 cards
void Deck :: populate(){

    int numCards = 0;

    // for 4 different suits
    for (int i = 0; i < 13; i++) {

        // for 13 ranks (13 * 4 = 52)
        for (int j = 0; j < 4; j++) {

            // get card object and use card constructor
            Card card = Card(i, j);

            // copy to the card array
            cards[numCards] = Card(i, j);

            // get a count variable here
            numCards ++;
        }

        // double check it's running 52 times, from 0-51 (52 times), so use x>50
        if (numCards > 50){
            break;
        }
    }
}



// shuffles the cards in the deck by performing cardsLeft^2 swaps of two randomly chosen cards in the deck
void Deck :: shuffle() {

    // cardsLeft^2 times
    for (int j = 0; j < cardsLeft * cardsLeft; j++) {

        // get two random number from
        int shuffleA = rand() % cardsLeft;
        int shuffleB = rand() % cardsLeft;

        // swap
        swap (cards[shuffleA], cards[shuffleB]);

    }
}


// removes a card from the deck and returns its value,
Card Deck :: removeCard() {

    // if this card is not yet chosen
    if (thiscard < arraySize) {

        // subtract one from the cards left
        cardsLeft--;

        // return teh cardsLeft value
        return (cards[thiscard++]);
    }

    // the the chosen card is out of the range, which means there are no cards left
    else {

        cout << "No cards left." << endl;
    }
}




// add a card to the deck (or returns false if there is no physical space in the deck.
bool Deck :: addCard(Card card){

    // if the cardsLeft doesn't reach 0, then run
    if (cardsLeft != 0){
        // enter the card value to the cards array
        cards[thiscard] = card;
        thiscard++;
        // return true
        return true;
    }

    // if there are no more cards
    else{
        return false;
    }
}
