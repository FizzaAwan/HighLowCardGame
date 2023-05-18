#pragma once
#include <string>
 
class Card {
friend class Deck;
private:
  int card_index;
  Card (int index) { card_index = index; }
public:
  Card () { card_index = 52; }
  char suit () const;
  char value () const;
  std::string str () const;
};
 
class Deck {
private:
  Card cards[52];
  int used_count;
public:
  Deck ();
  Card deal () { return cards[used_count++]; }
  void shuffle ();
  int size () const { return 52 - used_count; }
};
 
class Hand {
private:
  Card cards[52];
  int count; // Number of elements in cards that is occupied
public:
  Hand () { count = 0; }
  void add (const Card& c) { cards[count++] = c; }
  Card card (int index) const { return cards[index]; }
  void clear () { count = 0; }
  void remove (int index) { cards[index] = cards[--count]; }
  int size () const { return count; }
  std::string str () const;
};

class Score: public Card {    //score class inherits from Card class
public:
  bool compare(char last_card, char next_card, char highlow) const;   //funtion that compares two card using a given strategy and return a true or false. 
};