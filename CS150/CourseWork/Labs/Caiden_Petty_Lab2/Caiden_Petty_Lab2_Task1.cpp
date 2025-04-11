#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x1, y1, x2, y2, side1, side2, distance;

    cout << "Please enter the value for x1, y1, x2, and y2." << endl;

    cin >> x1 >> y1 >> x2 >> y2;

    side1 = x2 - x1;
    side2 = y2 - y1;
    distance = sqrt(side1*side1 + side2*side2);
    cout << "The distance between the two points is "<<distance <<endl;

    return 0;
}
