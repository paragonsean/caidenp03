#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

#include "agent.h"
//includes all the libraries and files
using namespace std;

void agent::setPiece(char p1ece)
{
    piece = p1ece;
}

char agent::getPiece()
{
    return piece;
}
//set and get my agent
void agent::setX(int pX)
{
    x = pX;
}

int agent::getX()
{
    return x;
}

void agent::setY(int pY)
{
    y = pY;
}

int agent::getY()
{
    return y;
}
//set and get x and y
void agent::moveUp()
{
    /*char temp = piece[x][y];
    temp = ' ';
    piece[x][y]==piece[x][y+1];*/
    x--;
}

void agent::moveRight()
{
    /*char temp == piece[x][y];
    temp = ' ';
    piece[x][y]==piece[x+1][y];*/
    y++;
}

void agent::moveLeft()
{
    /*char temp == piece[x][y];
    temp = ' ';
    piece[x][y]==piece[x-1][y];*/
    y--;
}

void agent::moveDown()
{
    /*char temp == piece[x][y];
    temp = ' ';
    piece[x][y]==piece[x][y-1];*/
    x++;
}
//make functions for the agent to move
/*void agent::pieceMove()
{
while (y != 2)
{
    if(piece[x][y+1]=' ')
        agent.moveUp();
    else if(piece[x][y+1]='X')
    {
        if(piece[x+1][y]!='|')
            agent.moveRight();
        else if(piece[x+1][y]='|')
        {
            if(piece[x-1][y]!='X')
                agent.moveLeft();
            else if(piece[x-1][y]='X')
            {
                agent.moveDown();
                agent.moveLeft();
            }
            }
        }
    }
}*/

void agent::pieceSpawn()
{
    y = rand() % (13)+1;
    x = 13;
}
