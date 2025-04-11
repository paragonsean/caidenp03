#include <iostream>///program to illustrate the switch statement

using namespace std;

int main()
{
    ///declare variables
    char grade;
    ///prompt the user to enter his/her grade
    cout << "Enter your midterm grade and press return: ";
    cin >> grade;
    ///User switch() structure and test the grade and output the message
    switch(grade)
    {
case 'A':
    cout << "Excellent!";
case 'B':
    cout << "Very good!";
case 'C':
    cout << "Passing. \n";
    break;
case 'D':
case 'F':
    cout << "Not good. " << "Go study. \n";
    break;
    cout << "That is not a possible grade. \n";
    }
    cout << endl<<endl;

    return 0;
}
