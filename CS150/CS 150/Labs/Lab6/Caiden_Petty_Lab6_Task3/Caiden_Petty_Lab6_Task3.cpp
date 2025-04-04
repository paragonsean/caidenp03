#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
///declare the variables
int temperature, minimum =0, sum =0, i, day =0;
///declare input stream
ifstream inData;
///open input file
inData.open("input.txt");
/// read the temperature
inData>> temperature; ///reading the first value
minimum = temperature;///set this to the minimum
sum= temperature;///set the sum equal to the temperature

cout << "Temperature Record: " <<endl;
cout << left << setw(10) << "Month"
     << left << setw(3) << "Day"
     << right << setw(13)<< "Temperature" << endl;

cout << left << setw(10) << "January"
     << left << setw(3) << i
     << right << setw(13)<< temperature << endl;

///run a loop to read the data and calculate the minimum
for(i=2; i<=31; i++)
{
    ///read the temperature
    inData>> temperature;
    sum = sum + temperature;
    ///display the temperature
    cout << left << setw(10) << "January"
         << left << setw(3) << i
         << right << setw(13)<< temperature << endl;
    ///compare temperature with the current minimum
    if (temperature<minimum)
    {
        minimum=temperature; ///update the minimum
        day=i; ///update the day

    }
}
///display the minimum to the screen
cout << fixed << showpoint << setprecision(2);
cout << "\nThe average temperature in January is " << sum/31.0;
cout << "\nThe lowest temperature was in January " << day;
cout << "\nThe lowest temperature was " << minimum<<endl << endl;

///close the file
inData.close();
    return 0;
}
