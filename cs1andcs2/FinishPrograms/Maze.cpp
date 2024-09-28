#include <iostream>
#include<cstring>
#include<ctime>
using namespace std;

void mazeboard(char maze[12][12])
{
	char wall = '#';
	char space = '*';
	int rng;
	int start;
	int end;
	srand(time(0));

	//maze boarder and path
	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 12; col++)
		{
			if (row && col > 0 && row && col < 12)
			{
				rng = rand() % 2;
				if (rng == 0)
				{
					maze[row][col] = space;
				}
				else if (rng == 1)
				{
					maze[row][col] = wall;
				}

			}
			else if (row == 0 && 12)
			{
				maze[row][col] = space;
			}
			else if (col == 0 && 12)
			{
				maze[row][col] = space;
			}
		}
	}

	//start
	start = rand() % 10;
	maze[0][start] = '#';
	end = rand() % 10;
	maze[11][end] = '#';
}

void mazeprint(char maze[12][12])
{
	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 12; col++)
		{
			cout << maze[row][col];
		}
		cout << endl;
	}
}

bool safe(char maze[12][12], int x, int y)
{
	if (x >= 0 && x < 12 && y >= 0 && y < 12 && maze[x][y] == 1)
	{
		return true;
	}

	return false;
}

bool solvemaze(char maze[12][12], int x, int y)
{
	if (x==12 - 1 && y == 12 -1)
	{
		maze[x][y] = '*';
		return true;
	}

	if (safe(maze, x, y) == true)
	{
		maze[x][y] = '*';
		if (solvemaze(maze, x + 1, y) == true)
		{
			return true;
		}
		if (solvemaze(maze, x, y + 1) == true)
		{
			return true;
		}
		maze[x][y] = '*';
		return false;
	}
	return false;
}

int main()
{
	char maze[12][12];
	mazeboard(maze);
	mazeprint(maze);
	bool yes = solvemaze(maze, 12, 12);
	if(yes==true){
		cout << "can be solved" <<endl;
	}
	else{
		cout << "can't be solved" <<endl;
	}
	return 0;
}