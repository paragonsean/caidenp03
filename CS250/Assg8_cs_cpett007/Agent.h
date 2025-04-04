#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

//includes all the libraries and files
using namespace std;

class agent{
public:
    void pieceMove();
    char getPiece();
    void pieceSpawn();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void setPiece(char p1ece);
    int getX();
    int getY();
    void setX(int pX);
    void setY(int pY);
private:
    int x;
    int y;
    char piece;
};
//class for the moving agent to include variables to move and functions
#endif // AGENT_H_INCLUDED
