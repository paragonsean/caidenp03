#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
    double boardArea;
    double boardLength;  //y
    double boardWidth;   //z
    double bVolume, bHt;

    double maxVolBoxBoardLn;
    double maxVolBoxBoardWd;
    double maxVolBoxHt;
    double maxVolBox;

	cout << fixed << showpoint << setprecision(3);

    cout << "Enter the area of the board: ";
    cin >> boardArea;
    cout << endl;

    boardWidth = 0.001;
    maxVolBox = 0;

    while (boardWidth <= boardArea)
    {
        boardLength = boardArea / boardWidth;

        double sqrSide;  //x
        double boxVolume;

        double minSide;
        if (boardLength <= boardWidth)
            minSide = boardLength;
        else
            minSide = boardWidth;

        sqrSide = 0.001;    //initialize the side of the square

        while (2 * sqrSide <= minSide)
        {
            boxVolume = (boardLength -  2 * sqrSide) *
                     (boardWidth -  2 * sqrSide) * sqrSide;

            if (bVolume < boxVolume)
            {
                bVolume = boxVolume;
                bHt = sqrSide;
            }

            sqrSide += 0.001;  //increment the side of the square
        }



        if (maxVolBox < bVolume)
        {
            maxVolBoxBoardLn = boardLength;
            maxVolBoxBoardWd = boardWidth;
            maxVolBoxHt = bHt;
            maxVolBox = bVolume;
        }

        boardWidth += 0.001;
    }

    cout << "Length of the cardboard to maximize the volume: "
        << maxVolBoxBoardLn << endl
        << "Width of the cardboard to maximize the volume: "
        << maxVolBoxBoardLn << endl;

    cout << "Length of the box with maximum volume: "
         << maxVolBoxBoardLn - 2 * maxVolBoxHt << endl
         << "Width of the box with maximum volume: "
         << maxVolBoxBoardWd - 2 * maxVolBoxHt  << endl
         << "Height of the box with maximum volume: " << maxVolBoxHt << endl
         << "Maximum Volume: " << maxVolBox << endl;

	return 0;
}
