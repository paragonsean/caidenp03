#include "ref.h"

referee::referee()
{
    //ctor
}
referee::referee(board &b)
{
    //ctor
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

bool referee::checkIfCaptured(board &b, int y, int x, int i)
{
    /*switch(i)
    {
    case 0:
        if (b.getGrid(y+1,x) == 'x')
        {

        }
    }*/
}

/*bool referee::checkEnemyNearby(board &b, int y, int x, int i)
{

}*/

bool referee::checkForBypass(board &b, int y1, int x1, int y2, int x2)
{
    int temp = 0;
    int temp2 = 0;
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
            if(b.getGrid(y1+2, x1) == ' ')
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

        for(int i = 0; i < ((x2 - x1)/2) ; i++)
        {
            if(b.getGrid(y1, temp-2) == ' ')
            {
                temp2++;
            }
            temp = temp - 2;
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
    else //right
    {
        temp = x1;

        for(int i = 0; i < ((x1 - x2)/2) ; i++)
        {
            if(b.getGrid(y1, x1+2) == ' ')
            {
                temp2++;
            }
            temp = temp + 2;
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
