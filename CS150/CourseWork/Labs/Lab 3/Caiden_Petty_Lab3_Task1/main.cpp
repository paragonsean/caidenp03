#include <iostream>
#include <iomanip>

using namespace std;

const double POUNDS_IN_KILOGRAM = 2.2;

int main()
{
    double weightInPounds;
    double weightInKilogram;

    cout << fixed << showpoint << setprecision(2);
    cout << "Enter the weight in kilograms: ";

   cin >> weightInKilogram;
   cout << endl;

   weightInPounds = weightInKilogram * POUNDS_IN_KILOGRAM;

   cout << "The equivalent weight in pounds is: " << weightInPounds << endl;

    return 0;
}
