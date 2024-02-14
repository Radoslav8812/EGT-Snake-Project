
#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <iostream>
#include <ctime>

using namespace std;

Deck::Deck() {
	
}

void Deck:: makeDeck() {

	vector<string> type = { "A", "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2" };
	vector<string> suit = { "spades", "diamonds", "hearts", "clubs" };

	for (int i = 0; i < 13; i++) {
		int num;

		if (type[i][0] >= '2' && type[i][0] <= '9') {
			num = type[i][0] - '0'; // cast to int
		}
		else if (type[i][0] == '1' || type[i][0] == 'J' || type[i][0] == 'Q' || type[i][0] == 'K') {
			num = 10;
		}
		else if (type[i][0] == 'A') {
			num = 11;
		}
		else {
			cout << "Invalid Card!" << endl;
			continue;
		}

		int points = num;          
		Card currentCard = { type[i], suit[i % 4], points };
		deckVect.push_back(currentCard);
	}
}

void Deck::shuffle()
{
	vector<Card> firstHalfVect;
	vector<Card> secondHalfVect;

	for (int i = 0; i * 2 < deckVect.size(); i++)
	{
		firstHalfVect.push_back(deckVect[i]);

	}
	for (int i = deckVect.size() / 2; i < deckVect.size(); i++)
	{
		secondHalfVect.push_back(deckVect[i]);

	}

	int count = 0;
	vector<Card&> newDeckVect;

	while (count != 26) {
		srand(time(NULL));

		int i = rand() % 26;
		newDeckVect.push_back(firstHalfVect[i]);

		int j = rand() % 26;
		newDeckVect.push_back(secondHalfVect[j]);

		count++;
	}
}

void Deck::displayDeck() {

	cout << "Deck of Cards: " << endl;

	for (auto& card : deckVect) {
		card.display();
	}
}