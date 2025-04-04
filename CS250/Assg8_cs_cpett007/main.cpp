#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

#include "Board.h"
#include "Agent.h"
//includes all the libraries and files
using namespace std;

bool playAgain();

int main()
{
    cout << "Press enter to start: " << endl;
    srand(time(0));
    //make rand true random
    board Board;
    //include board and type
    Board.setup();
    /*if(Board.Agent.getX()-1=='-')
    {
        playAgain();
        if (playAgain()==true)
*/
    do
    {
    Board.printGrid();
    //print grid

    Board.pieceMove();
    //call game to play
    //playAgain();
    }
    while(Board.Agent.getX() > 0);
    //ask player to play again
    return 0;
}

bool playAgain()
{
    char response;
    cout << "would you like to play again? (y/n)" << endl;
    cin >> response;
    if (response = 'y' || 'Y')
        return true;
    else if (response != 'y' || 'Y')
        return false;
}
