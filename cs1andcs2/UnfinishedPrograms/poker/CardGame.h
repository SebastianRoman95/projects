#include <iostream>
using namespace std;

class deckofcards
{

public:
	deckofcards();
	void shuffle();
	void deal();
	void cardflush();
private:
	int totaldecks[4][13] = { { 0,1,2,3 }, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13} };
};
