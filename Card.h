#ifndef BLINDMANSBLUFF_CARD_H
#define BLINDMANSBLUFF_CARD_H
#include <string>
using namespace std;

// ranks are ordered Ace-low and Queen-high
const string ranks[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","King","Queen"};


// suits are ordered alphabetically
const string suits[] = {"Clubs","Diamonds","Hearts","Spades"};


class Card {

    public:

        //default constructor
        Card();

        //alternate constructor
        Card(int rankInt, int suitInt);

        // one overloaded comparison operator (such as < or >), using the following ordering rules:
            //○	the rank is more important than the suit,
            //○	Aces are low and Queens are high, so that A < 2 < … < 10 < J < K < Q,
            //○	suits are ordered alphabetically, so that Clubs < Diamonds < Hearts < Spades.
        bool operator<(Card c);

        // returns a string specifying the value of the card in the format of “Jack of Hearts”,
        string print();

    private:

        // set private variables
        int rank;
        int suit;
        string name;

};

#endif //BLINDMANSBLUFF_CARD_H
