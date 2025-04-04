#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstdlib>

#include "board.h"
//includes all the libraries and files

using namespace std;

void board::setup()
{
    for(int p=0;p<15;p++)
    {
        grid[p][0]='|';
        grid[p][14]='|';
    }
    for(int k=0;k<15;k++)
    {
        grid[0][k] = '-';
        grid[14][k] = '-';
    }
    for (int t=1;t<14;t++)
    {
        for(int d=1;d<14;d++)
        {
            grid[t][d] = ' ';
        }
    }
    genObstacle();
    Agent.setPiece('@');
    Agent.pieceSpawn();

}

void board::printGrid(){
    cin.get();
    grid[Agent.getX()][Agent.getY()] = Agent.getPiece();
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
}
//generates the border for the grid and fills it in with spaces
void board::genObstacle()
{
    for(int x=1;x<12;x++)
    {
        grid[rand() % (13)+1][x]='X';
    }
}
//creates X randomly

void board::pieceMove()
{

    //while (Agent.getX() != 14)
{
    int y = Agent.getY();
    int x = Agent.getX();
    if(grid[x-1][y]=='-')
        cout << Agent.getX() << " , " << Agent.getY() << endl;
    if(grid[x-1][y]==' ')
        {Agent.moveUp();
        grid[x][y] = ' ';
        }
    else if(grid[x-1][y]=='X')
    {
        if(grid[x][y+1]!='|')
            {Agent.moveRight();
            grid[x][y] = ' ';}
        else if(grid[x][y+1]=='|')
        {
            if(grid[x][y-1]!='X')
                {Agent.moveLeft();
                grid[x][y] = ' ';}
            else if(grid[x][y-1]=='X')
            {
                Agent.moveDown();
                grid[x][y] = ' ';
                Agent.moveLeft();
                grid[x][y] = ' ';
            }
            }
        }
    }
}
