#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "~~~Miles Calculator~~~" << endl;
    double fuelTankCapacity;
    double milesPerGallon;
    double drivableMiles;
    // this is initializing the variables we will use later to calculate miles per gallon

    cout << "Enter the amount of gallons you have left in your vehicle: " << endl;
    cin >> fuelTankCapacity;
    // the user puts in the amount of gas they have left
    cout << "Enter miles per gallon: " << endl;
    cin >> milesPerGallon;
    // the user puts in their vehicle's miles per gallon
    drivableMiles = (fuelTankCapacity * milesPerGallon);
    cout << "Your drivable miles left: " << drivableMiles << endl;
    // the program displays how much further they can drive

    return 0;
}
