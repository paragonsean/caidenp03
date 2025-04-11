#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int side1, side2, side3;//declare the variables

    cout << "Enter the lengths of the sides of the triangle: " << endl;
    cin >> side1 >> side2 >> side3;
    cout << endl;

    if((pow(side1,2) == (pow(side2,2) + pow(side3,2))) ||
        (pow(side2,2) == (pow(side1,2) + pow(side3,2))) ||
        (pow(side3,2) == (pow(side1,2) + pow(side2,2))))
    {
        cout << "It is a right angled triangle." << endl;
    }
    else{
        cout << "It is not a right angled triangle." << endl;
    }
    return 0;
}
