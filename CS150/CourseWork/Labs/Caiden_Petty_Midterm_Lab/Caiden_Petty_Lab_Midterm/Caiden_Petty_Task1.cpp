///Caiden Petty 01204093
#include <iostream>

using namespace std;

int main()
{
    int time, speed;///initialize variables

    cout << "Enter the time in seconds: " << endl;
    cin >> time;///prompt and read the time


    if (time >= 0 && time <=15)///checks first gap
        {
        speed = 4 * time;///formula for first gap
        }
    if (time > 15 && time < 240)///checks second gap
        {
        speed = 60;///second gap answer
        }
    if (time >= 240 && time <= 250)///checks third gap
        {
        speed = (-6 * time) + 1500;/// third gap formula
        }
    if (time > 250)///no formula
        {
        cout << "Enter the time in seconds: " << endl;///try again within the range
        cin >> time;
        }

    cout << "The speed of the car is " << speed << " miles per hour" << endl;///output to user

    return 0;
}
