//Afham Bashir. 2.14.20.
#include <iostream>
#include "card.h"
#include <algorithm>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std; 

int main() {

srand(time(0));   //allows rand funtion for the deck 
Deck d;           //creates Deck varaible d. 
Card c1;          // creates the inital card
Card c2;         // creates the next card. 
Score s;         // creates varaible for score class
d.shuffle();    // shuffles the deck for the game. 

int win;        // integer variabel to count the number of correct rounds. 
char highlow;   // char for the strategy the player picks. 
int exit=0;     //creates exit varaible for the inner [do while] loop, cannot use h or l as sentiental values for logical expression for the "while", that would results in infinie loops because of the logical tautology.   

for( int i=1; i<= 10; i++){      // outer for loops plays 10 rounds, 
  c1= d.deal();                  //each round the first card gets dealt a new card. 
  c2= d.deal();                  //each round the next card gets dealt new card. 
  cout <<"\nRound "<< i << "\n"<<            // displays round number using i as counter. 
    "Is the next card higher or lower than "<< c1.value() << c1.suit()<< "?"<<endl; // outputs card value and suit. 
  do{                                // inner do while loop, so only h and l can be entered as characters. 
    cout <<"Enter 'h' or 'l': " ; 
    cin >> highlow; 
    if (highlow == 'h' || highlow == 'l') { exit =1; }
  } while( exit == 0); 

  cout << "The next card is " << c2.value()<<c2.suit() <<". ";  //outputs the next card. 
  if(s.compare(c1.value(), c2.value(), highlow) == true){       //if the comparsion returns true they win. 
    win ++;                                                     //correct increaments the number of wins. 
    cout << " You are correct!" <<endl;}                       
  else if (s.compare(c1.value(), c2.value(), highlow) == false){   //if the compasrions returns false, player guess incorrect. 
        cout << "Inncorect. " <<endl; }                           // wins are not increamented. 
}

cout << "\nYour Score is " << win << " out of 10" <<endl;   //once the for loop ends after 10 round the score is output. 
 
return 0; 
}

//doesnt have input validation that would result in a score value to be be inaccurate, and the app curently accepts other input than 'h' or 'l'.  
//doesn't support the scenario where the the next card is the same value