#include "card.h"
#include <algorithm>
#include <cstdlib>
using namespace std;
 
char Card::suit () const {
  const char suits[] = {'H','S','D','C','X'};
  return suits[card_index / 13];
}
 
char Card::value () const {
  const char values[] =
    {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
  if (card_index == 52)
    return 'X';
  return values[card_index % 13];
}
 
std::string Card::str () const {
  std::string s;
  s += value();
  s += suit();
  return s;
}
 
Deck::Deck () {
  for (int i = 0; i < 52; i++) {
    Card c(i);
    cards[i] = c;
  }
  used_count = 0;
}
 
void Deck::shuffle () {
  for (int i = 0; i < 52; i++)
    swap(cards[i], cards[rand() % 52]);
  used_count = 0;
}
 
std::string Hand::str () const {
  std::string s;
  for (int i = 0; i < count; i++) {
    if (i > 0)
      s += "-";
    s += cards[i].str();
  }
  return s;
}

bool Score::compare(char last_card, char next_card, char highlow) const{

int last_card_converted;    //creates and int varaible to hold the converted char of last card. 
int next_card_converted;    //creates and int varaible to hold the converted char of last card.

if (last_card >= '2' && last_card <= '9'){                  // if the card is between 2 and 9
  last_card_converted = last_card - '1';}      // substract int value of 1's ascii's value and converts to int. 
  else if (last_card == 'T') { last_card_converted = 10; }    //T,J,Q,K,A aren't sequental ascii values, hence they 
       if (last_card == 'J') { last_card_converted = 11; }    // need differnt conditional statments than 2-9. 
       if (last_card == 'Q') { last_card_converted = 12; }
       if (last_card == 'K') { last_card_converted = 13; }
       if (last_card == 'A') { last_card_converted = 14; }    //givens 10, jack, queen, king, and ace value. 

if (next_card >= '2' && next_card <= '9'){                   //repeats the conversion above, expect for the next card. 
  next_card_converted = next_card - '1';}
  else if (next_card == 'T') { next_card_converted = 10; }
       if (next_card == 'J') { next_card_converted = 11; }
       if (next_card == 'Q') { next_card_converted = 12; }
       if (next_card == 'K') { next_card_converted = 13; }
       if (next_card == 'A') { next_card_converted = 14; }

switch(highlow){                                    // based on the stragety the players want to play
  case 'h':                                         // if that player inputs higher 
  if(next_card_converted > last_card_converted){    //if value of second card is higher it return a true, otherwise false 
      return true;}
    else return false; 
  case 'l':                                         //if the player inputs lower. 
    if(next_card_converted < last_card_converted){  //if the second card is lower than the first only then returns true. 
      return true;}
    else return false; 
}

return false;                                     
}
