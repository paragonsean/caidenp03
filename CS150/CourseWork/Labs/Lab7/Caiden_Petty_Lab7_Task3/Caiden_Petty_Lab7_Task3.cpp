#include <iostream>

using namespace std;

const double METERS_PER_FOOT = 0.3048;
const double INCHES_PER_FOOT = 12.0;

///functions prototype
void input (int& feet, double& inches);

void convert (int feet, double inches, double& meters);

void output (int feet, double inches, double meters);


int main()
{
    /// declare the variables
    int feet;
    double inches, meters;
    char ans;

    do
    {
        input (feet, inches);
        convert (feet, inches, meters);
        output ( feet, inches, meters);

        ///ask the user if he or she wants to continue
        cout << "Y or y continues, any other character quits "
             << endl;

        /// read the user's choice
        cin >> ans;
    } while ('Y' == ans || 'y' == ans);
    return 0;
}

///input function reads the user's input
void input (int& feet, double& inches)
{
    ///prompt the user to enter in feet
    cout << "Enter feet as an integer: " << flush;

    ///read
    cin>> feet;

    ///prompt the user to enter the inches
    cout << "Enter inches: " << flush;

    ///read
    cin >> inches;
}


///convert the user's input into meters
void convert (int feet, double inches, double& meters)
{
    meters = METERS_PER_FOOT * (feet + inches/INCHES_PER_FOOT);
}

///output displays the output
void output (int feet, double inches, double meters)
{
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);

    ///print output to the screen
    cout << "the value of feet, inches " << feet << " "
         << inches << endl
         << " converted to meters, centimeters is "
         << meters << endl;
}
