#include"CardGame.cpp"
using namespace std;

int main()
{
	deckofcards deckofcards;
	deckofcards.shuffle();
	deckofcards.deal();
	deckofcards.cardflush();
	return 0;
}
