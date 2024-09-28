#include <iostream>
using namespace std;

void print(int board4x4[B][B])
{
	static int q = 1;
	printf("%d-\n", q++);
	for (int a = 0; a < B; a++)
	{
		for (int c = 0; c <B; c++)
		{
			printf(" %d ", board4x4[a][c]);
			printf("\n");
		}
	}
	printf("\n");
}

//check the left side of the board
//however once row than col fail resets to row 2, etc
bool checkboardrow(int board4x4[B][B], int col, int row)
{
	int r, i;
	for (int r = 0; r < col; r++)
	{
		if (board4x4[row][r])
			return false;
	}
	for (r = row, i = col; i >= 0 && r >= 0; i--, r--)
	{
		if (board4x4[i][r])
			return false;
	}
	for (r = row, i = col; r >= 0 && i < B; i++, r--)
	{
		if (board4x4[i][r])
			return false;
	}

	return true;
}

//however this if statement with bool also allows to reset row but calls top
bool checkboardcol(int board4x4[B][B], int col)
{
	if (col == B)
	{
		print(board4x4);
		return true;
	}

	bool rest = false;
	for (int i = 0; i < B; i++)
	{
		//fill the board by col until the board is filled
		if (checkboardrow(board4x4, i, col))
		{
			board4x4[i][col] = 1;
			rest = checkboardcol(board4x4, col + 1) || rest;
			board4x4[i][col] = 0;
		}
	}
	return rest;
}

void solutions()
{
    int B=4;
	int board4x4[B][B];
	memset(board4x4[B][B], 0, sizeof(board4x4));

	if (checkboardcol(board4x4, 0) == false)
	{
		printf("Solution does not exist");
		return;
	}
	return;
}

int main()
{
	solutions();
	return 0;
}

