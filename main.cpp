#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {

    // welcome message
    cout << endl << endl << "****************  Welcome to TAO's Blind Man's Bluff  *********************" << endl << endl;

    // starter codes
    bool play, invalid, guessedHigher;
    string response;

    int nWin = 0, nLoss = 0, nTie = 0;
    srand(time(NULL));

    // see if the user wants to play
    play = true;

    // create card object for computer's card
    Card computerChoice;

    // create card object for user's card
    Card userChoice;

    // create deck object
    Deck deck;

    // create the discard pile for used cards
    Deck discard;

    // populate the deck
    deck.populate();

    // shuffle the deack
    deck.shuffle();

    // intialize a count variable to break the loop in 26 times
    int count = 1;

    // use while-loop to check the conditions of continuation of playing
    while(play == true && count < 27) {

        // give computer a card and remove it from the deck
        computerChoice = deck.removeCard();

        // give the user a card and remove it from the deck
        userChoice = deck.removeCard();

        // add the computer's card to the discard pile
        discard.addCard(computerChoice);

        // add the user's card to the discard pile
        discard.addCard(userChoice);

        // print the computer's card
        cout << "No. " << count << " try:" << endl;
        cout << " *** Computer's card:【" << computerChoice.print() << "】*** " << endl;

        // set invalid as true to enter the following loop
        invalid = true;

        // while the user's type in is valid
        while(invalid) {

            // ask for user's input
            cout << "     Do you think your card is higher or lower? (H/L)  " ;
            cin >> response;

            // if the input is H, then the guess is higher, guessedHigher is true
            // the input is right
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            }

            // if the input is L, then the guess is lower, guessedHigher is false
            // the input is right
            else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            }

            // if the input is not H/L, then give a message and ask for re-type
            // the input is false
            else {
                // invalid response, ask again
                cout << "     Invalid response..." << endl;
                invalid = true;
            }
        }

        // determines the outcome
        // right guess
        if((computerChoice < userChoice && guessedHigher) || (userChoice < computerChoice && !guessedHigher)) {
            cout << "     Great! You're right." << endl;
            nWin++;
        }

        // wrong guess
        else if((userChoice < computerChoice && guessedHigher) || (computerChoice < userChoice && !guessedHigher)) {
            cout << "     Sorry, you're wrong." << endl;
            nLoss++;
        }

        // tie? Maybe not possible in this case
        else {
            cout << "     It's a tie:" << endl;
            nTie++;
        }

        // print out the user's own card
        cout << " *** Your card is:【" << userChoice.print() << "】*** "<< endl ;

        // count cards played throughout the game to make more informed decisions as the deck gets smaller
        if (count > 20 && count < 27){
            cout << "     Warning: Almost Running out of Cards! Still Have: " << 27 - count << " Left." << endl;
        }

        // ask user to play again
        invalid = true;

        // while true
        while(invalid) {

            // ask for the choice of continuing the game or not
            cout << "     Play again? (Y/N)  " ;
            cin >> response;

            // continue
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            }

            // end
            else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            }

            // wrong input
            else {
                // invalid response, ask again
                cout << "     Invalid response..." << endl;
                invalid = true;
            }
        }

        // count the times of playing
        // if the counts here gets to 26 after adding, then jump out of the loop
        count++;

        cout << endl;
    }

    // print message as running out of cards
    if (count == 27){
        cout<<"All of the cards were used!"<<endl;
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl << endl;
    cout << "****************  Hope to See U Play TAO's BMB Again  *********************" << endl;

    return 0;
}
