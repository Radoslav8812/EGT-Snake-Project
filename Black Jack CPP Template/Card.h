

#include <string>
#include <iostream>

using namespace std;

class Card{

private:
	string type;
	string suit;
	int points;

public:
	Card(string type, string suit, int points);

	void setType(string);
	string getType();

	void setSuit(string);
	string getSuit();

	void setPoints(int);
	int getPoints();

	void display();

	
};