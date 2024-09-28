#include <iostream>
using namespace std;

int moveknight(int x, int y, int movep, int piece[k][k],
    int xMove[], int yMove[]);

int check(int x, int y, int piece[k][k])
{
    return (x >= 0 && x < k && y >= 0 &&
        y < k && piece[x][y] == -1);
}

void board(int piece[k][k])
{
    for (int x = 0; x < k; x++)
    {
        for (int y = 0; y < k; y++)
            printf(" %2d ", piece[x][y]);
        printf("\n");
    }
}

int knight()
{
    int piece[k][k];

    for (int x = 0; x < k; x++)
        for (int y = 0; y < k; y++)
            piece[x][y] = -1;
        
    int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

    piece[0][0] = 0;
    if (moveknight(0, 0, 1, piece, xMove, yMove) == 0)
    {
        printf("Solution does not exist");
        return 0;
    }
    else
        board(piece);

    return 1;
}

int moveknight(int x, int y, int movep, int piece[k][k],
    int xMove[k], int yMove[k])
{
    int u, next_x, next_y;
    if (movep == k * k)
        return 1;

    for (u = 0; u < 8; u++)
    {
        next_x = x + xMove[u];
        next_y = y + yMove[u];
        if (check(next_x, next_y, piece))
        {
            piece[next_x][next_y] = movep;
            if (moveknight(next_x, next_y, movep + 1, piece,
                xMove, yMove) == 1)
            {
                return 1;
            }
            else
            {
                piece[next_x][next_y] = -1;
            }
        }
    }
    return 0;
}

int main()
{
    knight();
    return 0;
}
