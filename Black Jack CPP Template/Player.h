#include"Card.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {

private:
	int capital;
	int bet;
	int points;
	bool win;
	vector<Card> playerCardsVect;

public:
	Player(int initialCapital = 100000);

	void addCard(Card& card);
	void addPoints(int pointsToAdd);
	void placeBet(int betAmount);
	bool hasEnoughCapital();
	bool isBusted();
	void determineWin();
	void resetPlayer();

	int getCapital();
	int getBet();
	int getPoints();
	bool getWinStatus();
};