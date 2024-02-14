
#include "Player.h"

Player::Player(int initialCapital) : capital(initialCapital), bet(0), points(0), win(false) {

}

int Player::getCapital() {
	return this -> capital;
}

int Player::getBet() {
	return this -> bet;
}

int Player::getPoints() {
	return this -> points;
}

bool Player::getWinStatus() {
	return this -> win;
}

void Player::addCard(Card& card) {

	playerCardsVect.push_back(card);
}

void Player::addPoints(int pointsToAdd) {
	points += pointsToAdd;
}

void Player::placeBet(int betAmount) {

	if (betAmount <= capital) {
		bet = betAmount;
		capital -= bet;
	}
	else {
		cout << "No money for more bets! " << endl;
	}
}

bool Player::hasEnoughCapital() {

	return capital > 0;
}

bool Player::isBusted() {
	
	return points > 21;
}

void Player::determineWin() {
	// Assuming the dealer's hand is known (you need a Dealer class with its own logic)
	int dealerPoints /* get the total points of the dealer's hand */;

	if (isBusted()) {
		// Player busted, so the player loses
		win = false;
	}
	else if (dealerPoints > 21 || points > dealerPoints) {
		// Either the dealer busted or the player's points are higher, so the player wins
		win = true;
	}
	else if (points == dealerPoints) {
		// It's a tie (push) - neither wins or loses
		win = false;  // Adjust based on your tie rules
	}
	else {
		// Dealer's points are higher, so the player loses
		win = false;
	}
}

void Player::resetPlayer() {

	playerCardsVect.clear();
	points = 0;
	bet = 0;
	win = false;
}