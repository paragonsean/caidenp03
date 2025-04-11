#include <iostream>
#include <string>
#include "romanType.h"

using namespace std;

int main()
{
   ///Variables
   romanType roman;

   string romanString;

   ///prompt the user to enter a roman number and read it into romanString
   cout << "Enter a roman number: ";
   cin >> romanString;
   cout<< endl;

   ///call the setRoman number to set the romanNum value of roman
   ///Calculate and output the number equivalent of the roman numeral
   roman.setRoman(romanString);

   ///print out the roman numeral and equivalent number
   cout << "The equivalent of the roman numeral "
        << romanString << " is ";
    roman.printPositiveInteger();
    cout << endl;

    return 0;
}
