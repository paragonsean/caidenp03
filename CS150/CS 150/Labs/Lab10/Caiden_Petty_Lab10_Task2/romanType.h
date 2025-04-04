#include <iostream>

using namespace std;

///Class romanType

class romanType
{
public:
    ///sets the roman numeral to the value stored in string
    ///Also calls the romanToPositive integer function
    void setRoman(string);

    ///Converts the roman numeral to integer
    void romanToPositiveInteger();

    ///Outputs the roman numeral to integer
    void printPositiveInteger() const;

    ///outputs the value stored in num
    void printRoman() const;

    ///constructor
    romanType();
    romanType(string);

private:
    string romanNum; ///String variable to store the roman numeral equivalent of num

    int num; ///Integer variable to represent the value of the roman numeral
};
