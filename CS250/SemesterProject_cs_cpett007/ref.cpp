#include "ref.h"

referee::referee()
{
    score[0]=0;
    score[1]=0;
}

bool referee::checkValidPlayer(board &b, int y, int x, int i)
{
    switch(i)
    {
    case 0:
        if(b.getGrid(y, x) == 'o' || b.getGrid(y, x) == 'O')
            return true;
        else
            return false;
    case 1:
        if(b.getGrid(y, x) == 'x' || b.getGrid(y, x) == 'X')
            return true;
        else
            return false;
    }
}

bool referee::checkForBypass(board &b, int y1, int x1, int y2, int x2)
{
    int temp = 0;
    int temp2 = 0;//temporary variables to check if updated space is possible

    if(y2 < y1)//up
    {
        temp = y1;

        for(int i = 0; i < ((y1 - y2)/2); i++)
        {
            if(b.getGrid(temp-2, x1) == ' ')
            {
                temp2++;
            }
            temp = temp - 2;
        }
        if(temp2 == ((y1 - y2)/2))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if(y2 > y1)//down
    {
        temp = y1;

        for(int i = 0; i < ((y2 - y1)/2) ; i++)
        {
            if(b.getGrid(temp+2, x1) == ' ')
            {
                temp2++;
            }
            temp = temp + 2;
        }
        if(temp2 == ((y2 - y1)/2))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else if(x2 < x1)//left
    {
        temp = x1;

        for(int i = 0; i < ((x1 - x2)/2) ; i++)
        {
            if(b.getGrid(y1, temp-2) == ' ')
            {
                temp2++;
            }
            temp = temp - 2;
        }
        if(temp2 == ((x1 - x2)/2))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else //right
    {
        temp = x1;

        for(int i = 0; i < ((x2 - x1)/2) ; i++)
        {
            if(b.getGrid(y1, temp+2) == ' ')
            {
                temp2++;
            }
            temp = temp + 2;
        }
        if(temp2 == ((x2 - x1)/2))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

bool referee::checkForOneDir(board &b, int y1, int x1, int y2, int x2)
{
    if(y1 == y2 && x1 != x2)
    {
        return true;
    }
    else if(x1 == x2 && y1 != y2)
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool referee::checkIfMoveisValid(board &b, int y1, int x1, int y2, int x2, int i)
{
    if (checkValidPlayer(b, y1, x1, i) == true && checkForOneDir(b, y1, x1, y2, x2) == true)
    {
        if(checkForBypass(b, y1, x1, y2, x2) == false)
        {
            return true;
        }
        else if(checkForBypass(b, y1, x1, y2, x2) == true)
        {
            cout << "Please enter a valid move." << endl;
            return false;
        }
    }
    else
    {
        cout << "Please enter a valid move." << endl;
        return false;
    }
}

void referee::setScore(int i)
{
    switch(i)
    {
    case 0:
        score[i] = score[i] + 1;
    case 1:
        score[i] = score[i] +1;
    }
}

void referee::checkIfCaptured(board &b, int y, int x, int i, char a, char A, char B)
{
    if(checkCrossCapture(b, y, x, a, A, B) == true)
    {
        score[i] = score[i] + 1;
    }
}

bool referee::checkCrossCapture(board &b, int y, int x, char a, char A, char B)
{
    if(b.getGrid(y-2, x) != ' ' && b.getGrid(y-2, x) != a && b.getGrid(y-2, x) != A)
    {
        if(b.getGrid(y-4, x) == a || b.getGrid(y-4, x) == A)
        {
            b.makePlayers(y-2, x, ' ');
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(b.getGrid(y+2, x) != ' ' && b.getGrid(y+2, x) != a && b.getGrid(y+2, x) != A)
    {
        if(b.getGrid(y+4, x) == a || b.getGrid(y+4, x) == A)
        {
            b.makePlayers(y+2, x, ' ');
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(b.getGrid(y, x-2) != ' ' && b.getGrid(y, x-2) != a && b.getGrid(y, x-2) != A)
    {
        if(b.getGrid(y, x-4) == a || b.getGrid(y, x-4) == A)
        {
            b.makePlayers(y, x-2, ' ');
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(b.getGrid(y, x+2) != ' ' && b.getGrid(y, x+2) != a && b.getGrid(y, x+2) != A)
    {
        if(b.getGrid(y, x+4) == a || b.getGrid(y, x+4) == A)
        {
            b.makePlayers(y, x+2, ' ');
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool referee::checkEndConditions()
{
    if(score[0]==8)
    {
        cout << "congrats player 1, you win!" << endl;
        return true;
    }
    else if(score[1]==8)
    {
        cout << "congrats player 2, you win!" << endl;
        return true;
    }
    else
        return false;
}

/*bool referee::checkDuke(b, y, x, i, a, A)
{
    if(b.getGrid(y, x-2) != ' ' && b.getGrid(y, x-2) != a && b.getGrid(y, x-2) != A)
}*/
