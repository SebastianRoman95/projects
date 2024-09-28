#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include"CardGame.h"
using namespace std;

deckofcards::deckofcards()
{
	int count = 0;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 12; col++)
		{
			count++;
			totaldecks[row][col] = count;
		}
	}
}

void deckofcards::shuffle()
{
	int numbers1 = 0;
	int names1 = 0;
	int numbers2 = 0;
	int names2 = 0;
	int flip;
	srand(time(NULL));

	for (int card = 1; card < 52; card++)
	{
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 12; c++)
			{
				numbers1 = rand() % 13 + 1;
				names1 = rand() % 4 + 1;
				numbers2 = rand() % 13 + 1;
				names2 = rand() % 4 + 1;
				

				flip = totaldecks[names1][numbers1];
				totaldecks[names1][numbers1] = totaldecks[names2][numbers2];
				totaldecks[names2][numbers2] = flip;
			}
		}
	}

}

void deckofcards::deal()
{
	static const char* suit[4] = { "Hearts ", "Diamonds", "Clubs", "Spades" };
	static const char* face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	//deals
	for (int card = 0; card < 5; card++)
	{
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 12; col++)
			{
				if (totaldecks[row][col] == card)
				{
					cout << setw(5) << right << face[col] << " of " << setw(8) << left << suit[row];
				}
			}
		}
	}


}

void deckofcards::cardflush()
{
	static const char* suit[4] = { "Hearts ", "Diamonds", "Clubs", "Spades" };
	static const char* face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	
	for(int card = 0; card < 5; card++)
	{
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 12; col++)
			{
				if (face[col] == "Ace" || face[col] == "King" || face[col] == "Queen" || face[col] == "Jack" || face[col] == "Ten")
				{
					cout << "Roayl flush" << endl;
				}
				if(face[col]== face[col + 1] && face[col + 2] && face[col + 3] && face[col + 4])
				{
					cout << "Straight";
				}
				if (suit[row]==suit[row+1]&& suit[row + 2] && suit[row + 3] && suit[row + 4])
				{
					cout << "Straight flush";
				}
				if (face[col] && face[col+1] && face[col + 2] == "Ace" && face[col + 3] && face[col + 4] == "King")
				{
					cout << "Full house";
				}
				if (suit[row]&&face[0]== suit[row + 1] && face[0] && suit[row+2] && face[0] && suit[row + 3] && face[0] && suit[row + 4] && face[0])
				{
					cout << "Flush";
				}
				if (face[col] == face[col + 1]  && face[col + 2])
				{ 
					cout << "Three of a kind";
				}
				if (face[col] == face[col + 1] && face[col + 2] && face[col + 3])
				{
					cout << "Four of a kind";
				}
				if (face[col] == face[col + 1] && face[col+2] == face[col + 3])
				{
					cout << "Two Pair";
				}
				if (face[col] == face[col + 1])
				{
					cout << "One Pair";
				}
				if (face[col] == "Ace")
				{
					cout << "High Card";
				}
			}
		}
	}
}
