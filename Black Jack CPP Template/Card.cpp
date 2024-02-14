

#include "Card.h"
#include <iostream>

Card::Card(string type, string suit, int points){

}

void Card::setType(string type) {
	this->type = type;
}
string Card::getType() {
	return this -> type;
}

void Card::setSuit(string suit) {
	this->suit = suit;
}
string Card::getSuit() {
	return this->suit;
}

void Card::setPoints(int points) {
	this->points = points;
}

void Card::display() {

	cout << "Card Type -> " << getType() << endl;
	cout << "Card Suit -> " << getSuit() << endl;
	cout << "Card Points -> " << getPoints() << endl;
}