#include"TicTacToe.h"

ttt::ttt()
{
	board[size][size];
}

bool ttt::validmove(int r, int c)
{
	if (board[r][c]!=symbol)
	{
		board[r][c] = symbol;
		return true;
	}
	else
	{
		return false;
	}
}

ttt::status ttt::gamestatus()
{
	// double for loop board[r][0] == board[r][c] && board[r][c] == board[r][c] &&  board[r][size]
	//for loop 0=r r>0 r<size r=size
	bool wld;
		
	if (wld == true)
	{
		//row
		for (int r = 0; r < size; r++)
		{
			if (board[r][0] == board[r][1] && board[r][1] == board[r][size] && board[r][0] != symbol)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//col
		for (int c = 0; c < size; c++)
		{
			if (board[0][c] == board[1][c] && board[1][c] == board[size][c] && board[0][c] != symbol)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//diagonal left
		for (int d = 0; d < size; d++)
		{
			if (board[0][0] == board[1][1] && board[1][1] == board[size][size] && board[0][0] != symbol)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//diagonal right
		for (int d = 0; d < size; d++)
		{
			if (board[0][size] == board[1][1] && board[1][1] == board[size][0] && board[0][size] != symbol)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//win
		return 0;
	}
	else if (wld==false)
	{
		//draw
		return 1;
	}
}

void ttt::printboard()
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			cout << board[row][col] << " ";
		}
	}
}

void ttt::makemove()
{
	printboard();
	while (true)
	{
		if (xomove('X'))
		{
			break;
		}
		else if (xomove('O'))
		{
			break;
		}
	}
}

bool ttt::xomove(int symbol)
{
	int x;
	int y;

	do
	{
		cout << "Player" << static_cast<char> (symbol) << " enter move: ";
		cin >> x >> y;
		cout << '\n';
	} while (!validmove(x, y));

	board[x][y] = symbol;
	printboard();
	status xostatus = gamestatus();

	if (xostatus == Win)
	{
		cout << "Player " << static_cast <char> (symbol) << " wins!\n";
		return true;
	}
	else if (xostatus == Draw)
	{
		cout << "Game is a draw. \n";
		return true;
	}
	else
	{
		return false;
	}
}
