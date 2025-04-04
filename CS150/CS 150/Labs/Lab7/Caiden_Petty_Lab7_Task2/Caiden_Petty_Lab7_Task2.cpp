#include <iostream>

using namespace std;

///functions prototypes
void input( int& hours24, int& minutes);
void convert( int& hours, char& AMPM);
void output( int hours, int minutes, char AMPM);

int main()
{
    ///declare variables
    int hours, minutes;
    char AMPM, ans;
    do{
        input( hours, minutes);
        convert ( hours, AMPM);
        output( hours, minutes, AMPM);

        ///ask the user to continue
        cout << "Enter Y or y to continue"
             << " anything else quits."
             << endl;

        ///read the user's input
        cin >> ans;
    } while ( 'Y'==ans || 'y'==ans);///check choice

    return 0;
}

///input function gets the time
void input(int& hours24, int& minutes)
{
    ///declare variables
    char colon;

    ///prompt the user to enter the time
    cout << "Enter the time in a 24 hour format HH:MM "
         << endl;

    ///read the time
    cin >> hours24 >> colon >> minutes;
}

///convert function converts the time
void convert(int& hours, char& AMPM)
{
    if (hours > 12)///definitely in the afternoon
    {
        hours = hours - 12;
        AMPM = 'P';
    }
    else if (12 == hours) /// afternoon hour
        AMPM = 'P'; /// int hours is not changed
    else if (0 == hours) ///early morning hour
    {
        hours = hours + 12;
        AMPM = 'A';
    }
    else /// (hours < 12) ///definitely morning hour
        AMPM = 'A'; ///hours is unchanged
}

///output function prints the output
void output ( int hours, int minutes, char AMPM)
{

    ///print the time
    cout <<"Time in 12 hour format: " << endl
         << hours << ":" << minutes << " "
         << AMPM << 'M' << endl;
}
