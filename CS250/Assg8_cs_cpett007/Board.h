#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED
#include "Agent.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
//includes all the libraries and files
using namespace std;

class board{
public:
    void setup();
    agent Agent;
    string getposX();
    string getposY();
    void setposX();
    void setposY();
    void printGrid();
    void genObstacle();
    void pieceMove();
private:
    char grid[15][15];
    string posX;
    string posY;
};
//class for board to include board variables and functions
#endif // BOARD_H_INCLUDED
