///Caiden Petty 01204093
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int i=1993;/// i is for the year, this makes it easy to display the year when the loop continues
    int y=0;/// y is for the years since 1993, this makes the formula usable
    double formula;///this will be what we set the formula equal to

    cout << "Quantity of paper recycled from 1993 to 2007" << endl;
    cout << "In thousands of tons." << endl;///displaying the title
    cout << "----------------------------------------------" << endl;
    cout << left << "year "///the names of the columns
         << right << " paper recycled" << endl;
    while (i <= 2007)///as long as the year is below 2008
    {
    formula = (-0.0013 * pow(y,4)) + (0.0513 * pow(y,3)) - (0.662 * pow(y,2)) + (4.128 * y) + 35.75;///the formula for calculating the paper recycled
    cout << i << right << "   " << fixed << showpoint << setprecision(4) << formula << endl;///aligning the table and displaying year and paper recycled
     y++;///increment years since 1993
     i++;///increment year
    }
    return 0;
}
