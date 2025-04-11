#include <iostream>
using namespace std;
int main()
{
 int total = 0, number;///make total declared and equal to zero
 cout << "Enter the numbers to be added and end with -1: ";
 cin >> number;
 while (number != -1)
 {
 total = total + number;
 cin >> number; ///read the new integer as number
 }
 cout << endl;
 cout << "Total = " << total << endl;
 return 0;
}
