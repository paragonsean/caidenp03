#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ///declare variables
    double hoursCarParked;
    double billingAmount;
    ///set output to two decimals
    cout << fixed << showpoint;
    cout << setprecision(2);

    ///Prompt the user to enter the number of hours parked
    cout << "Enter the number of hours the car is parked";
    cin >> hoursCarParked;
    cout << endl;

    ///calculate parking fee
    if(hoursCarParked <= 3)
    {
        billingAmount = 5;
    }
    else if (3 < hoursCarParked && hoursCarParked <= 9){
        billingAmount = 6 * static_cast<int>(hoursCarParked + 1);
    }
    else{
        billingAmount = 60;
    }
    ///Outputs the parking fee
    cout << "Please pay: $" << billingAmount << endl;

    return 0;
}
