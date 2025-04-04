#include "board.h"
#include "player.h"
#include "ref.h"

#include <iostream>

using namespace std;

void game(board b, player p);
void requestMovement(int i, int &tempX, int &tempY, char tempC);
int convertXCord(int x);
int convertYCord(char a);

int main()
{
    board newgame;
    newgame.makeBoard();
    player newplayer(newgame);
    newgame.printBoard();

    game(newgame, newplayer);

    return 0;
}

void game(board b, player p)
{
    referee r;
    int tempX1 = 0;
    int tempY1 = 0;
    int tempX2 = 0;
    int tempY2 = 0;
    int i = 0;
    char tempC = ' ';

    while(r.checkEndConditions()==false)
    switch(i)
    {
    case 0:
        //Switch statement to change turns throughout program
        Incorrect://A reset point to go back
        cout << "Player " << i+1 << ": (O) Which piece do you want to move?" << endl;
        requestMovement(i, tempX1, tempY1, tempC);
        cout << "Player " << i+1 << ": Where do you want to move?" << endl;
        requestMovement(i, tempX2, tempY2, tempC);

        if(r.checkIfMoveisValid(b, tempY1, tempX1, tempY2, tempX2, i) == true)
        {

            p.movePlayer(b, tempX1 ,tempY1 ,tempX2 ,tempY2 ,i);

            i++;

        }
        else
        {
           b.printBoard();
           cout << "Please reenter your moves" << endl;

           goto Incorrect;
        }

        break;
    case 1:
        Incorrect2:
        cout << "Player " << i+1 << ": (X) Which piece do you want to move?" << endl;
        requestMovement(i, tempX1, tempY1, tempC);
        cout << "Player " << i+1 << ": Where do you want to move?" << endl;
        requestMovement(i, tempX2, tempY2, tempC);

        if(r.checkIfMoveisValid(b, tempY1, tempX1, tempY2, tempX2, i) == true)
        {
            p.movePlayer(b, tempX1 ,tempY1 ,tempX2 ,tempY2 ,i);
            i--;
        }
        else
        {
           b.printBoard();
           cout << "Please reenter your moves" << endl;
           goto Incorrect2;
        }
        break;
    }
}

void requestMovement(int i, int &tempX, int &tempY, char tempC)
{
    do
    {
        cout << "Enter Letter then Number: ";
        cin >> tempC >> tempX;

        tempX = convertXCord(tempX);
        tempY = convertYCord(tempC);
    }
    while(tempX ==0 || tempY == 0);
}

int convertXCord(int x)
{
    switch(x)
    {
        //case to change between actual size and board size
    case 0:
        return 3;
        break;
    case 1:
        return 5;
        break;
    case 2:
        return 7;
        break;
    case 3:
        return 9;
        break;
    case 4:
        return 11;
        break;
    case 5:
        return 13;
        break;
    case 6:
        return 15;
        break;
    case 7:
        return 17;
        break;
    default:
        //if the switch is not met check this
        cout << "Number not in range, try again." << endl;
        return 0;
    }
}
int convertYCord(char a)
{
    switch(a)
    {
        //switch to move between the alphabetic row and the integer grid
    case 'A':
    case 'a':
        return 2;
        break;
    case 'B':
    case 'b':
        return 4;
        break;
    case 'C':
    case 'c':
        return 6;
        break;
    case 'D':
    case 'd':
        return 8;
        break;
    case 'E':
    case 'e':
        return 10;
        break;
    case 'F':
    case 'f':
        return 12;
        break;
    case 'G':
    case 'g':
        return 14;
        break;
    case 'H':
    case 'h':
        return 16;
        break;
    default:
        //letter not in range
        cout << "Letter not found, try again." << endl;
        return 0;
    }
}
