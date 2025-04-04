#include "board.h"

using namespace std;
board::board()
{
    for(int i = 0; i < 18; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            grid[i][j] = ' ';
        }
    }
}
void board::makeBoard()
{
    for(int i = 2; i < 19; i++)
    {
        grid[1][i] = '-';
        grid[17][i] = '-';
    }
    for(int i = 2; i < 17; i++)
    {
        grid[i][2] = '|';
        grid[i][18] = '|';
    }

    for(int i = 1; i < 10; i++)
    {
        for(int j = 3; j < 18; j++)
        {
            grid[(2*i)+1][j] = '-';
        }
    }
    for(int i = 1; i < 9; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            grid[i*2][j*2] = '|';
        }
    }


    for(int i = 1; i < 17; i++)
    {
        for(int j = 1; j < 9; j++)
        {
            grid[i*2][0] = 64+i;
            grid[0][(2*j)+1] = 47+j;
        }
    }
}

void board::makePlayers(int y, int& x, char a)
{
    grid[y][x] = a;
}

void board::updateBoard(int oldY, int oldX, int y, int x, char a)
{
    grid[oldY][oldX] = ' ';
    grid[y][x] = a;

    printBoard();
}

void board::printBoard()
{
    system("cls");

    for(int i = 0; i < 18; i++)
    {
        for(int j = 0; j < 19; j++)
        {
             cout << grid[i][j];
        }
        cout << endl;
    }
}

char board::getGrid(int y, int x)
{
    return grid[y][x];
}
