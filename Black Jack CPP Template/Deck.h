
#include "Card.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Deck {

private:
	vector<Card&> deckVect;

public:
	Deck();

	void makeDeck();
	void shuffle();

	void displayDeck();

};