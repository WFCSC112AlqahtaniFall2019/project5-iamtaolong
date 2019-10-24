#include "Card.h"
#include <iostream>
using namespace std;

//default constructor
Card :: Card(){
    rank = 0;
    suit = 0;

}


//alternate constructor
Card :: Card(int rankInt, int suitInt){
    this -> rank = rankInt;
    this -> suit = suitInt;
}


// one overloaded comparison operator
bool Card :: operator<(Card card){

        // <
        if (this->rank < card.rank){
            return true;
        }
        // =
        else if (this->rank == card.rank){
            return this->suit < card.suit;
        }
        // >
        else if (this->rank > card.rank){
            return false;
        }
    }

// returns a string specifying the value of the card in the format of “Jack of Hearts”,
string Card :: print(){
    name = ranks[rank]+ " of "+ suits[suit];
    return name;
}
