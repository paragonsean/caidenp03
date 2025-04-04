#include "board.h"
#include "player.h"
#include "ref.h"

#include <iostream>

using namespace std;

void game(board b, player p, referee r);
void requestMovement(int i, int &tempX, int &tempY, char tempC);
int convertXCord(int x);
int convertYCord(char a);

int main()
{
    board newgame;
    newgame.makeBoard();

    referee newref(newgame);
    player newplayer(newgame);


    newgame.printBoard();

    game(newgame, newplayer, newref);

    return 0;
}

void game(board b, player p, referee r)
{
    int tempX1 = 0;
    int tempY1 = 0;
    int tempX2 = 0;
    int tempY2 = 0;
    int i = 0;
    char tempC = ' ';

    Next_Turn:
    switch(playerTurn)
    {
    case 0:
        //Switch statement to change turns throughout program
        Incorrect://A reset point to go back
        cout << "Player " << playerTurn+1 << ": Which piece do you want to move?" << endl;
        requestMovement(i, tempX1, tempY1, tempC);
        cout << "Player " << playerTurn+1 << ": Where do you want to move?" << endl;
        requestMovement(i, tempX2, tempY2, tempC);

        if(r.checkIfMoveisValid(b, tempY1, tempX1, tempY2, tempX2, i) == true)
        {
            p.movePlayer(b, tempX1 ,tempY1 ,tempX2 ,tempY2 ,i);
            playerTurn++;

            goto Next_Turn;
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
        cout << "Player " << playerTurn+1 << ": Which piece do you want to move?" << endl;
        requestMovement(i, tempX1, tempY1, tempC);
        cout << "Player " << playerTurn+1 << ": Where do you want to move?" << endl;
        requestMovement(i, tempX2, tempY2, tempC);

        if(r.checkIfMoveisValid(b, tempY1, tempX1, tempY2, tempX2, i) == true)
        {
            p.movePlayer(b, tempX1 ,tempY1 ,tempX2 ,tempY2 ,i);
            playerTurn--;

            goto Next_Turn;
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
        cout << "Please enter a valid number" << endl;
        return 0;
    }
}
int convertYCord(char a)
{
    switch(a)
    {
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
        cout << "Please enter a valid letter" << endl;
        return 0;
    }
}
